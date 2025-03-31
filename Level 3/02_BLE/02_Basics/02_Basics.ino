void setup() {
  Serial.begin(9600);
  Serial.println("Comms Established!");
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');

    if (command == "LED OFF") {
      Serial.println("LED is turned OFF");
    } else if (command == "LED ON") {
      Serial.println("LED is turned ON");
    }
  }
}
