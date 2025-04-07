#include <Servo.h>

Servo s;

void setup() {
  s.attach(7);
  Serial.begin(9600);
  Serial.println("Bluetooth module is ready!");
  s.write(0);
}

void loop() {
  if (Serial.available()) {
    int angle = Serial.parseInt();

    if (angle >=0 && angle <= 180) {
      s.write(angle);
      Serial.print("Rotated servo to angle: ");
      Serial.println(angle);
    } else {
      Serial.print("Invalid angle: ");
      Serial.println(angle);
    }
  }
}
