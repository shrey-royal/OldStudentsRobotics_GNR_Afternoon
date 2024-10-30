/*
Components Used:
  1. LED

Pins Details:
1. LED:
+ve -> 9
-ve -> GND
*/

void blinkSetup(int ledPin) {
  pinMode(ledPin, OUTPUT);
}

void blinkLoop(int ledPin) {  
  digitalWrite(led, HIGH);
  delay(500);
  
  digitalWrite(led, LOW);
  delay(500);
}