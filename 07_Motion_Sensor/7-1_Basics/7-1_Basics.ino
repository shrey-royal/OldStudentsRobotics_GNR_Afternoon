int pirSensor = 2;
int cs;
int ls = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(pirSensor, INPUT);
}

void loop() {
  ls = cs;
  cs = digitalRead(pirSensor);

  if(ls == LOW && cs == HIGH) {
    Serial.println("Motion Detected!");
  } else if(ls == HIGH && cs == LOW) {
    Serial.println("Motion Stopped!");
  }
}
