#include <Adafruit_NeoPixel.h>

#define PIN 7
#define NUMPIXELS 24

Adafruit_NeoPixel ls = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  ls.begin();
  ls.show();
}

void loop() {
  int i = 0;
  for (; i < 8; i++) {
    ls.setPixelColor(i, ls.Color(255, 0, 0));
    ls.show();
    delay(100);
  }

  for (; i < 16; i++) {
    ls.setPixelColor(i, ls.Color(0, 255, 0));
    ls.show();
    delay(100);
  }

  for (; i < NUMPIXELS; i++) {
    ls.setPixelColor(i, ls.Color(0, 0, 255));
    ls.show();
    delay(100);
  }

  for (; i >= 0; i--) {
    ls.setPixelColor(i, ls.Color(0, 0, 0));
    ls.show();
    delay(100);
  }
  delay(1000);
}
