/*
// 2-1
int btnPin = 7;
int led = 13;

// int lastState = HIGH;
int currState;
*/

// 2-2
int btnPin = 7;
int led = 13;
int btnState;

void setup() {
  btnLedSetup(btnPin, led);
}

void loop() {
  btnLedLoop(btnPin, led, btnState);
}
