#include <Servo.h>

#define MPIN 3

Servo sm;

void setup() {
  sm.attach(MPIN);
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 180; i+=1) {
    sm.write(i);
    delay(10);
  }
  delay(1000);
  for (int i = 180; i >= 0; i-=1) {
    sm.write(i);
    delay(10);
  }
  delay(1000);
}
