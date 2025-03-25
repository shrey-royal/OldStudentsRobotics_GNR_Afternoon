#include <Adafruit_NeoPixel.h>

#define PIN 7
#define NUMPIXELS 24

Adafruit_NeoPixel ls = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  ls.begin();
  ls.show();
}

void loop() {
  for (int i = 0; i < NUMPIXELS; i++) {
    if (i % 3 == 0) {
      ls.setPixelColor(i, ls.Color(255, 0, 0));
    } else if (i % 3 == 1) {
      ls.setPixelColor(i, ls.Color(0, 255, 0));
    } else {
      ls.setPixelColor(i, ls.Color(0, 0, 255));
    }
    ls.show();
    delay(100);
  }

  // Turn off LEDs one by one in the same order
  for (int i = 0; i < NUMPIXELS; i++) {
    ls.setPixelColor(i, ls.Color(0, 0, 0));
    ls.show();
    delay(100);
  }
}
