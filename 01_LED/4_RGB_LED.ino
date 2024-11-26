void rgbSetup(int r, int g, int b) {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void rgbLoop(int r, int g, int b, int rv, int gv, int bv) {
  analogWrite(r, rv);
  analogWrite(g, gv);
  analogWrite(b, bv);
}

/*
void rgbLoop(int r, int g, int b) {
  analogWrite(r, 255);
  analogWrite(g, 0);
  analogWrite(b, 0);
  delay(1000);

  analogWrite(r, 0);
  analogWrite(g, 255);
  analogWrite(b, 0);
  delay(1000);

  analogWrite(r, 0);
  analogWrite(g, 0);
  analogWrite(b, 255);
  delay(1000);
}
*/