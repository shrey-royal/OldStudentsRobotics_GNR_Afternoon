int potPin = A0;
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void specSetup() {
  pinMode(potPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void specLoop() {
  int potValue = analogRead(potPin);

  int redValue = map(potValue, 0, 1023, 0, 255);
  int greenValue = map(potValue, 0, 1023, 0, 255);
  int blueValue = map(potValue, 0, 1023, 0, 255);

  Serial.println(potValue);
  
  if (potValue < 341) {
    redValue = 255 - map(potValue, 0, 341, 0, 255);
    greenValue = map(potValue, 0, 341, 0, 255);
    blueValue = 0;
  }
  else if (potValue < 682) {
    greenValue = 255 - map(potValue, 341, 682, 0, 255);
    blueValue = map(potValue, 341, 682, 0, 255);
    redValue = 0;
  }
  else {
    blueValue = 255 - map(potValue, 682, 1023, 0, 255);
    redValue = map(potValue, 682, 1023, 0, 255);
    greenValue = 0;
  }

  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
  
  delay(10);
}