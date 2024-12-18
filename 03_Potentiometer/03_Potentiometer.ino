int p = A0, value, led = 3;

void setup() {
  pinMode(p, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(A0);
  Serial.println(value);
  analogWrite(led, value/4);
}