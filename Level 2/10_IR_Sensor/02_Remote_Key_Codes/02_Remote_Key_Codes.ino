#include "IRremote.hpp"

#define IR_RECEIVE_PIN 2

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()){
    uint16_t command = IrReceiver.decodedIRData.command;
    Serial.println(command);
    delay(100);
    IrReceiver.resume();
  }
}
