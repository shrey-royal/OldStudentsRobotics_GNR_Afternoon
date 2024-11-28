void btnLedSetup(int btnPin, int led) {
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void btnLedLoop(int btnPin, int led, int btnState) {
  btnState = digitalRead(btnPin);

  if (btnState == HIGH) {
    digitalWrite(led, LOW);
  }

  if (btnState == LOW) {
    digitalWrite(led, HIGH);
  }
}