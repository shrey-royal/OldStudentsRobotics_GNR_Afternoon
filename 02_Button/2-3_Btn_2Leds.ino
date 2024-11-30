void btnLedsSetup(int btn, int l1, int l2) {
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
}

void btnLedsLoop(int l1, int l2) {
  int ls, cs;
  cs = digitalRead(btn);

  if (ls == LOW && cs == HIGH) {
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    ls = cs;
  }

  if (ls == HIGH && cs == LOW) {
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    ls = cs;
  }
}