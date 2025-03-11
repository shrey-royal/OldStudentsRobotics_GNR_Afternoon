int ir = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ir, INPUT);
}

void loop() {
  int state = digitalRead(ir);

  if (state == LOW) Serial.println("The obstacle is present");
  else Serial.println("The obstacle is NOT present");

  delay(100);
}
