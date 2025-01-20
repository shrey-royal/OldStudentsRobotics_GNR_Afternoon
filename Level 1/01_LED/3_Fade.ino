/*
Components Used:
  1. LED

Pins Details:
1. Red LED
+ve -> A0
-ve -> GND
*/

void fadeSetup(int ledPin) {
  pinMode(ledPin, OUTPUT);
}

void fadeLoop(int ledPin) {
  for(int i=0; i<256; i+=5) {
    analogWrite(ledPin, i);
    delay(30);
  }
  delay(1000);
  
  for(int i=255; i>=0; i-=5) {
    analogWrite(ledPin, i);
    delay(30);
  }
  delay(1000);
}