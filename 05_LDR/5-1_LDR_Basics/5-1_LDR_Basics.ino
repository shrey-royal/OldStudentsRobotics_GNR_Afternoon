int ldr = 2;

void setup() {
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop() {
  int state = digitalRead(ldr);

  if (state == LOW)
    Serial.println("Lights are ON!");
  else
    Serial.println("Lights are OFF!");

  delay();
}