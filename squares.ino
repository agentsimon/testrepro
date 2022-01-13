// Simple NeoPixel test.  Lights just a few pixels at a time so a
// 1m strip can safely be powered from Arduino 5V pin.  Arduino
// may nonetheless hiccup when LEDs are first connected and not
// accept code.  So upload code first, unplug USB, connect pixels
// to GND FIRST, then +5V and digital pin 6, then re-plug USB.
// A working strip will show a few pixels moving down the line,
// cycling between red, green and blue.  If you get no response,
// might be connected to wrong end of strip (the end wires, if
// any, are no indication -- look instead for the data direction
// arrows printed on the strip).

#include <Adafruit_NeoPixel.h>

#define PIN      6
#define N_LEDS 64

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
int outer_leds[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 15, 16, 23, 24, 31, 32, 39, 40, 47, 48, 55, 56, 57, 58, 59, 60, 61, 62, 63};
int inner1_leds[] = {9, 10, 11, 12, 13, 14, 17, 22, 25, 30, 33, 38, 41, 46, 49, 50, 51, 52, 53, 54};
int inner2_leds[] = {18,19,20,21,26,29,34,37,42,43,44,45};
int inner3_leds[] = {27,28,35,36};

void setup() {
  Serial.begin(112500);
  strip.begin();
  strip.show();
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t ) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);

  }
  strip.show();
}
void loop() {
  const int arrLen = sizeof(outer_leds) / sizeof(outer_leds[0]);
  const int arrLen2 = sizeof(inner1_leds) / sizeof(inner1_leds[0]);
  const int arrLen3 = sizeof(inner2_leds) / sizeof(inner2_leds[0]);
  const int arrLen4 = sizeof(inner3_leds) / sizeof(inner3_leds[0]);
  Serial.print(arrLen);
  for (uint16_t i = 0; i < arrLen; i++) {
    strip.setPixelColor(outer_leds[i], strip.Color(255, 0, 0));
    Serial.println(outer_leds[i]);    strip.show();
  }
  delay(500);
  strip.fill(0, 0, 0);
  strip.show();
  for (uint16_t i2 = 0; i2 < arrLen2; i2++) {
    strip.setPixelColor(inner1_leds[i2], strip.Color(0, 255, 0));
    Serial.println(inner1_leds[i2]);
    strip.show();
  }

  delay(500);
  strip.fill(0, 0, 0);
  strip.show();
  for (uint16_t i3 = 0; i3 < arrLen3; i3++) {
    strip.setPixelColor(inner2_leds[i3], strip.Color(0, 0, 255));
    Serial.println(inner1_leds[i3]);
    strip.show();
  }

  delay(500);
  strip.fill(0, 0, 0);
  strip.show();
  for (uint16_t i4 = 0; i4 < arrLen4; i4++) {
    strip.setPixelColor(inner3_leds[i4], strip.Color(255, 255, 255));
    Serial.println(inner3_leds[i4]);
    strip.show();
  }
  delay(500);
  strip.fill(0, 0, 0);
  strip.show();
}
