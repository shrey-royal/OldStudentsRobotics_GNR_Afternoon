/*
Components Used:
  1. LED x2
  2. BreadBoard
  3. Jumper Wires

Pins Details:
1. White LED
+ve -> 10
-ve -> GND

2. Blue LED
+ve -> 9
-ve -> GND
*/

void multipleLedSetup(int l1, int l2) {
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
}

void multipleLedLoop(int l1, int l2) {
  //P1
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
  delay(random(80, 120));
  
  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
  delay(random(80, 120));

  //P2
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
  delay(random(80, 120));

  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
  delay(random(80, 120));

  //P3
  digitalWrite(l1, HIGH);
  digitalWrite(l2, HIGH);
  delay(random(80, 120));
  
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  delay(random(80, 120));
}