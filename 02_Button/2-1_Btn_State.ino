void btnStateSetup(int btnPin) {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(btnPin, INPUT_PULLUP);
}

void btnStateLoop(int lastState, int currState) {
  // put your main code here, to run repeatedly:
  currState = digitalRead(btnPin);
  Serial.println(currState);

  /*
  if (lastState == LOW && currState == HIGH) {
    Serial.println("The state changed from LOW to HIGH -> Button RELEASED");
  } else if (lastState == HIGH && currState == LOW) {
    Serial.println("The state changed from HIGH to LOW -> Button PRESSED");
  }
  lastState = currState;
  */
}
