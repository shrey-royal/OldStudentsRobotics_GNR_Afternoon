#include <WiFiS3.h>
#include <arduino_secrets.h>

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

WiFiServer server(80);
int led = LED_BUILTIN;
int status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  pinMode(led, OUTPUT);

  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("WiFi module not found!");
    while (true);
  }

  WiFi.config(IPAddress(192, 48, 56, 2));
  status = WiFi.beginAP(ssid, pass);

  if (status != WL_AP_LISTENING) {
    Serial.println("Failed to start AP");
    while (true);
  }

  delay(10000);
  server.begin();

  Serial.print("AP IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    String currentLine = "";
    String request = "";

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;

        if (c == '\n' && currentLine.length() == 0) {
          if (request.indexOf("GET /H") >= 0) digitalWrite(led, HIGH);
          if (request.indexOf("GET /L") >= 0) digitalWrite(led, LOW);

          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println();

          client.println("<p><a href=\"/H\">Turn LED ON</a></p>");
          client.println("<p><a href=\"/L\">Turn LED OFF</a></p>");
          client.println("<form method='POST' action='/submit'>");
          client.println("Name: <input name='username'><br>");
          client.println("Color: <input type='color' name='favcolor'><br>");
          client.println("<input type='submit' value='Submit'></form>");
          client.println();
          break;
        } else if (c != '\r') {
          currentLine += c;
        } else {
          currentLine = "";
        }

        if (request.indexOf("POST /submit") >= 0) {
          // Wait for headers to end
          while (client.available()) {
            String line = client.readStringUntil('\n');
            if (line == "\r") break;
          }

          // Read form body
          String body = "";
          while (client.available()) {
            body += (char)client.read();
          }

          Serial.print("POST Body: ");
          Serial.println(body); // Example: username=Alice&favcolor=%23ff0000

          // Parse form values
          int nameIndex = body.indexOf("username=");
          int colorIndex = body.indexOf("favcolor=");

          String username = (nameIndex >= 0) ? body.substring(nameIndex + 9, body.indexOf('&')) : "";
          String color = (colorIndex >= 0) ? body.substring(colorIndex + 12) : "";

          Serial.print("User: ");
          Serial.println(username);
          Serial.print("Color: #");
          Serial.println(color);

          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println();
          client.println("<h1>Form Received</h1>");
          client.print("<p>User: ");
          client.print(username);
          client.println("</p>");
          client.print("<p>Color: #");
          client.print(color);
          client.println("</p>");
          client.println("<a href='/'>Go Back</a>");
          break;
        }
      }
    }

    client.stop();
  }
}