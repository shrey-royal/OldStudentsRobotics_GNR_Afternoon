int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Bluetooth module is ready!");
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    if (command == "0") {
      digitalWrite(led, LOW);
      Serial.println("LED is turned OFF");
    } else if (command == "1") {
      digitalWrite(led, HIGH);
      Serial.println("LED is turned ON");
    }
  }
}
