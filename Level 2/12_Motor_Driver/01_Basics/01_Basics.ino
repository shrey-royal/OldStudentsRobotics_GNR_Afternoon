int m1 = 12, m2 = 13;
int en = 5;

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(en, OUTPUT);

  digitalWrite(en, HIGH); //Turns the I1, I2 ON
}

void loop() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  delay(1000);

  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  delay(1000);

  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  delay(1000);
    
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  delay(1000);
}