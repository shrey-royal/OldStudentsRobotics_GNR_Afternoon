#include <Keypad.h>

const int BUZZER_PIN = 11;
const int ROW_NUM = 4;
const int COLUMN_NUM = 4;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pin_rows[ROW_NUM] = {2, 3, 4, 5};
byte pin_columns[COLUMN_NUM] = {6, 7, 8, 9};

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_columns, ROW_NUM, COLUMN_NUM);

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
  }
  digitalWrite(BUZZER_PIN, LOW);
}
