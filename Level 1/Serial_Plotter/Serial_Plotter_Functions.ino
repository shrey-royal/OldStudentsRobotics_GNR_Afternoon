void sinewaveforms() {
  for (int i = 0; i < 360; i += 5) {
    float a = 1 * sin(i * M_PI / 180);
    float b = 2 * sin((i + 90) * M_PI / 180);
    float c = 5 * sin((i + 180) * M_PI / 180);
  
    Serial.print(a);
    Serial.print("\t");

    Serial.print(b);
    Serial.print("\t");

    Serial.println(c);

    delay(100);
  }
}


void readAnalog() {
  int a = analogRead(A0);
  int b = analogRead(A1);
  int c = analogRead(A2);
  int d = analogRead(A3);

  Serial.print(a);
  Serial.print(" ");
  Serial.print(b);
  Serial.print(" ");
  Serial.print(c);
  Serial.print(" ");
  Serial.println(d);
  delay(100);
}