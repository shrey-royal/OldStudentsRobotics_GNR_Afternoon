/*
// 2-1
int btnPin = 7;
int led = 13;

// int lastState = HIGH;
int currState;
*/

// 2-2
// int btnPin = 7;
// int led = 13;
// int btnState;


// 2-3  
int btn = 7;
int l1 = 4, l2 = 5;

void setup() {
  btnLedsSetup(btn, l1, l2);
}

void loop() {
  btnLedsLoop(l1, l2);
}
