String message = "Hello, World!\n";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Comms Established!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    message = Serial.readString();
  }
  Serial.print(message);
  delay(1000);
}
