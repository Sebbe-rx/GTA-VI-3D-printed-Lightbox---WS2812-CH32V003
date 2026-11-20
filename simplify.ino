#include <Adafruit_NeoPixel.h>

const int LED_PIN = PC1;
const int NUM_LEDS = 49;

Adafruit_NeoPixel strip(
  NUM_LEDS,
  LED_PIN,
  NEO_GRB + NEO_KHZ800
);

void setup() {
  strip.begin();
  strip.setBrightness(180);

  for (int led = 0; led < NUM_LEDS; led++) {

    // Position across the strip: 0.0 at the start, 1.0 at the end.
    float position = float(led) / (NUM_LEDS - 1);

    int red;
    int green;
    int blue;

    if (position < 0.5f) {
      // First half: pink -> purple.
      // Progress goes from 0.0 to 1.0 within this half.
      float progress = position * 2.0f;

      red   = 255 - 105 * progress;  // 255 -> 150
      green = 0;
      blue  = 160 + 50 * progress;  // 160 -> 210

    } else {
      // Second half: purple -> orange.
      float progress = (position - 0.5f) * 2.0f;

      red   = 150 + 105 * progress;  // 150 -> 255
      green = 110 * progress;        //   0 -> 110

      // Squaring the remaining fraction makes blue fade along a curve.
      float remaining = 1.0f - progress;
      blue = 210 * remaining * remaining;  // 210 -> 0
    }

    strip.setPixelColor(led, strip.Color(red, green, blue));
  }

  strip.show();
}

void loop() {
  // Nothing to update: the colours stay on.
}
