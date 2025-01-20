// 1_Blink declarations
// int led = 9;

//2_Multiple_LEDs declarations
// int b = 9;
// int w = 10;

//2-1_Multiple_LEDs declarations
// int l[] = {12, 11, 10, 9, 8};
// int size = sizeof(l)/sizeof(l[0]);

//3_Fade declarations
int led = 3;

void setup() {
  fadeSetup(led);
}

void loop() {
  fadeLoop(led);
}