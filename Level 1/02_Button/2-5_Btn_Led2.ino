void btnLedSetup2() {
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void btnLedLoop2() {
  btnState = digitalRead(btnPin);

  if (btnState == HIGH && lbs == LOW) {
    while(digitalRead(btnPin) == HIGH) {
      delay(10);
    }
    ledState = !ledState;
    digitalWrite(led, ledState ? HIGH : LOW);
  }
  lbs = btnState;
}