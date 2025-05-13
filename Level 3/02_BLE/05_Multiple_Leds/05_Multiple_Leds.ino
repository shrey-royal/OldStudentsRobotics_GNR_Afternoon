int l1 = 8, l2 = 9, l3 = 10, l4 = 11, l5 = 12, l6 = 13;

void setup() {
  Serial.begin(9600);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(l6, OUTPUT);
}

void loop() {  
  String command;
  if (Serial.available()) {
    command = Serial.readStringUntil("\n");
    if (command == "ON1") {
      digitalWrite(l1, HIGH);
    } else if (command == "OFF1") {
      digitalWrite(l1, LOW);
    } else if (command == "ON2") {
      digitalWrite(l2, HIGH);
    } else if (command == "OFF2") {
      digitalWrite(l2, LOW);
    } else if (command == "ON3") {
      digitalWrite(l3, HIGH);
    } else if (command == "OFF3") {
      digitalWrite(l3, LOW);
    } else if (command == "ON4") {
      digitalWrite(l4, HIGH);
    } else if (command == "OFF4") {
      digitalWrite(l4, LOW);
    } else if (command == "ON5") {
      digitalWrite(l5, HIGH);
    } else if (command == "OFF5") {
      digitalWrite(l5, LOW);
    } else if (command == "ON6") {
      digitalWrite(l6, HIGH);
    } else if (command == "OFF6") {
      digitalWrite(l6, LOW);
    }
  }
}
