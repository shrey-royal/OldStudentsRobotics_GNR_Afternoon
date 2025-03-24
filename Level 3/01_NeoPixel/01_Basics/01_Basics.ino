#include <Adafruit_NeoPixel.h>

#define PIN 7

Adafruit_NeoPixel ls = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  ls.begin();
  ls.show();
}

void loop() {
  for (int i = 0; i < 24; i++) {
    ls.setPixelColor(i, ls.Color(255, 0, 0));
    ls.show();
    delay(60);
  }

  for (int i = 0; i < 24; i++) {
    ls.setPixelColor(i, ls.Color(0, 255, 0));
    ls.show();
    delay(60);
  }

  for (int i = 0; i < 24; i++) {
    ls.setPixelColor(i, ls.Color(0, 0, 255));
    ls.show();
    delay(60);
  }

  ls.clear();
  ls.show();
  delay(2000);

  for (int times = 0; times < 4; times++) {
    for (int i = 0; i < 24; i++) {
      ls.setPixelColor(i, ls.Color(255, 255, 255));
    }
    ls.show();
    delay(250);

    for (int i = 0; i < 24; i++) {
      ls.setPixelColor(i, ls.Color(0, 0, 0));
    }
    ls.show();
    delay(250);
  }

  ls.clear();
  ls.show();
  delay(2000);
}
