/*
Components Used:
  1. LED x5
  2. BreadBoard
  3. Jumper Wires

Pins Details:
1. LED:
+ve -> 12
-ve -> GND

2. LED:
+ve -> 11
-ve -> GND

3. LED:
+ve -> 10
-ve -> GND

4. LED:
+ve -> 9
-ve -> GND

5. LED:
+ve -> 8
-ve -> GND
*/

void multipleLedSetup2(int l[], int n) {
  for(int i=0; i<n; i++) {
    pinMode(l[i], OUTPUT);
    digitalWrite(l[i], LOW);
  }
}

void multipleLedLoop2(int l[], int n) {
  /*
  // Pattern 1
  for(int i=0; i<n; i++) {
    digitalWrite(l[i], HIGH);
    delay(100);
  }
  
  for(int i=n-1; i>=0; i--) {
    digitalWrite(l[i], LOW);
    delay(100);
  }
  */
  /*
  // Pattern 2
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      digitalWrite(l[j], LOW);
    }
    digitalWrite(l[i], HIGH);
    
    delay(100);
  }

  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      digitalWrite(l[j], LOW);
    }
    digitalWrite(l[i], HIGH);
    
    delay(100);
  }

  for (int j = 0; j < n; j++) {
    digitalWrite(l[j], LOW);
  }

  delay(1000);
  */

  //Pattern 3
  for(int i=0; i<n; i++) {
    digitalWrite(l[i], HIGH);
  }
  delay(200);

  for(int i=0; i<n; i++) {
    digitalWrite(l[i], LOW);
  }
  delay(200);

}