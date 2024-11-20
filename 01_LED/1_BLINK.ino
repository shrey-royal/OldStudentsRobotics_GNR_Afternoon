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
  digitalWrite(ledPin, HIGH);
  delay(500);
  
  digitalWrite(ledPin, LOW);
  delay(500);
}