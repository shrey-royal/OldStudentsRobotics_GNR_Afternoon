#include<SPI.h>
#include<MFRC522.h>

#define SS_PIN 10
#define RST_PIN 5
#define BUZZER_PIN 7

MFRC522 rfid(SS_PIN, RST_PIN);

const byte validCards[][4] = {
  {0xA3, 0x66, 0x73, 0xFA},
  {0XC3, 0x45, 0xDF, 0xFD}
};
const int numValidCards = sizeof(validCards)/sizeof(validCards[0]);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("Tap RFID/NFC Tag on reader");
}

void loop() {
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Serial.print("UID: ");
    // for (int i = 0; i < rfid.uid.size; i++) {
    //   Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    //   Serial.print(rfid.uid.uidByte[i], HEX);
    // }
    // Serial.println();

    if (isCardValid(rfid.uid.uidByte, rfid.uid.size)) {
      Serial.println("Access Granted!");
      beepBuzzer(1);
    } else {
      Serial.println("Access Denied!");
      beepBuzzer(2);
    }

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
}

bool isCardValid(byte *uid, byte size) {
  for (int i = 0; i < numValidCards; i++) {
    bool match = true;
    for (int j = 0; j < size; j++) {
      if(uid[j] != validCards[i][j]) {
        match = false;
        break;
      }
    }
    if(match) return true;
  }
  return false;
}

void beepBuzzer(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
  }
}
