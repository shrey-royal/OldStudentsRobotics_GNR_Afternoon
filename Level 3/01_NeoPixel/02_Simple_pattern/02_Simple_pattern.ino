#include <Adafruit_NeoPixel.h>

#define PIN 7

Adafruit_NeoPixel ls = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  ls.begin();
  ls.show();
  Serial.begin(9600);
}

void loop() {
  for (int j = 0; j < 256; j++) {
    for (int i = 0; i < 24; i++) {
      ls.setPixelColor(i, ls.ColorHSV(j * 65536 / 256));
      Serial.println(j * 65536 / 256);
    }
    ls.show();
    delay(50);
  }
  delay(1000);
}
