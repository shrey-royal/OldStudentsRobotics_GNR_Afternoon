void BtnDebounceSetup(int BUTTON_PIN) {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void BtnDebounceLoop(int currentState, int lastSteadyState, int lastDebounceTime, int lastFlickerableState, int DEBOUNCE_DELAY, int BUTTON_PIN) {
  currentState = digitalRead(BUTTON_PIN);

  //check if button state is changed
  if(currentState != lastFlickerableState) {
    lastDebounceTime = millis();
    lastFlickerableState = currentState;
  }

  //check if button state is not changed
  if((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    if (currentState != lastSteadyState) {
        lastSteadyState = currentState;

        if(currentState == LOW) {
          Serial.println("Button pressed!");
        } else {
          Serial.println("Button released!");
        }
    }
  }
}