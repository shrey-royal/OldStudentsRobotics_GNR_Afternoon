/*
// 2-1
int btnPin = 7;
int led = 13;

// int lastState = HIGH;
int currState;


// 2-2
int btnPin = 7;
int led = 13;
int btnState;


// 2-3
int btn = 7;
int l1 = 4, l2 = 5;


//2-4
int BUTTON_PIN = 7;
int DEBOUNCE_DELAY = 50;

int lastSteadyState = HIGH;
int lastFlickerableState = HIGH;
int currentState;

unsigned long lastDebounceTime = 0;
*/

//2-5
int btnPin = 7;
int led = 10;
int btnState = 0, lbs = 0, ledState = false;

void setup() {
  btnLedSetup2();
}

void loop() {
  btnLedLoop2();
}
