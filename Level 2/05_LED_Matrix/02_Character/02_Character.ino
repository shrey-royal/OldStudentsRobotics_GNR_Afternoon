#include<MD_Parola.h>
#include<MD_MAX72XX.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3

MD_Parola ledMatrix = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  Serial.begin(9600);
  ledMatrix.begin();
  ledMatrix.setIntensity(15);  //0-15
  ledMatrix.displayClear();
}

void loop() {
  String str = "Default";
  if (ledMatrix.displayAnimate()) {
    ledMatrix.displayText(str.c_str(), PA_CENTER, 100, 0, PA_NO_EFFECT);
    ledMatrix.displayReset();
  }
}
