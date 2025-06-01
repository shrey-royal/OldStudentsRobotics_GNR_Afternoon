#include <WiFiS3.h>
#include <arduino_secrets.h>

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

WiFiServer server(80);
int led = LED_BUILTIN;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  pinMode(led, OUTPUT);
  connectToWiFi();
  server.begin();

  Serial.println("Web server started.");
  printWiFiStatus();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  if (!client.connected()) {
    client.stop();
    return;
  }

  String reqLine = client.readStringUntil('\n');
  reqLine.trim();

  // Serial.print("Request line: ");
  // Serial.println(reqLine);

  int contentLength = 0;
  while (true) {
    String headerLine = client.readStringUntil('\n');
    headerLine.trim();
    if (headerLine.length() == 0) break;

    // Serial.print("Header: ");
    // Serial.println(headerLine);

    if (headerLine.startsWith("Content-Length:")) {
      contentLength = headerLine.substring(15).toInt();
    }
  }

  if (reqLine.startsWith("GET /H")) {
    digitalWrite(led, HIGH);
    sendResponse(client, false, "");
  }
  else if (reqLine.startsWith("GET /L")) {
    digitalWrite(led, LOW);
    sendResponse(client, false, "");
  }

  else if (reqLine.startsWith("POST /submit")) {
    String postBody = "";
    int toRead = contentLength;
    while (toRead > 0) {
      while (client.available() && toRead > 0) {
        char c = client.read();
        postBody += c;
        toRead--;
      }
      delay(1);
    }

    // Serial.println("---- RAW POST BODY ----");
    // Serial.println(postBody);
    // Serial.println("------------------------");

    handlePostData(postBody);
    sendResponse(client, true, postBody);
  }
  else {
    sendResponse(client, false, "");
  }

  client.stop();
}

void connectToWiFi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);

  int attempts = 0;
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
    attempts++;
    if (attempts > 10) {
      Serial.println("\nFailed to connect to WiFi. Check SSID/PASS or 2.4GHz support.");
      while (true);
    }
  }

  Serial.println("\nConnected to WiFi!");

  while (WiFi.localIP() == IPAddress(0, 0, 0, 0)) {
    Serial.println("Waiting for IP address from DHCP...");
    delay(500);
  }
}

void printWiFiStatus() {
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  Serial.print("Access the device at: http://");
  Serial.println(ip);

  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  Serial.print("Signal Strength (RSSI): ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");

  // uint8_t mac[6];
  // WiFi.macAddress(mac);
  // Serial.print("MAC Address: ");
  // for (int i = 0; i < 6; i++) {
  //   if (mac[i] < 16) Serial.print("0");
  //   Serial.print(mac[i], HEX);
  //   if (i < 5) Serial.print(":");
  // }
  Serial.println();
}

void handlePostData(const String &body) {
  int nameIdx = body.indexOf("username=");
  int colorIdx = body.indexOf("favcolor=");

  if (nameIdx >= 0 && colorIdx >= 0) {
    int ampIdx = body.indexOf('&', nameIdx);
    String username;
    if (ampIdx != -1)
      username = body.substring(nameIdx + 9, ampIdx);
    else
      username = body.substring(nameIdx + 9);

    String color = body.substring(colorIdx + 12);

    Serial.print("User: "); Serial.println(username);
    Serial.print("Color: #"); Serial.println(color);
  } else {
    Serial.println("POST data not in expected format.");
  }
}

void sendResponse(WiFiClient &client, bool isPost, const String &body) {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type: text/html");
  client.println();  

  client.println("<html><body style='font-size:1.5em;'>");
  client.println("<h2>Web Server</h2>");
  client.println("<p><a href=\"/H\">Turn LED ON</a></p>");
  client.println("<p><a href=\"/L\">Turn LED OFF</a></p>");
  client.println("<form method='POST' action='/submit'>");
  client.println("Name: <input name='username'><br>");
  client.println("Color: <input type='color' name='favcolor'><br>");
  client.println("<input type='submit' value='Submit'>");
  client.println("</form>");

  if (isPost) {
    client.println("<h3>Form submitted!</h3>");
    client.println("<pre>" + body + "</pre>");
  }

  client.println("</body></html>");
}