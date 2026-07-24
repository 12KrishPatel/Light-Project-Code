#include <FastLED.h>

#define NUM_LEDS    256
#define DATA_PIN    4
#define BRIGHTNESS  64
#define BAUD_RATE   115200
#define FRAME_BYTES (NUM_LEDS * 3)

CRGB leds[NUM_LEDS];

// Compact default heart so the matrix isn't blank before a host connects.
const uint8_t HEART_BORDER[] PROGMEM = {
  34, 35, 36, 37, 42, 43, 44, 45, 49, 50, 54, 57, 61, 62, 65, 71, 72, 78,
  81, 94, 97, 110, 113, 126, 129, 130, 141, 142, 146, 147, 156, 157, 163,
  164, 171, 172, 180, 181, 186, 187, 197, 198, 201, 202, 214, 215, 216, 217
};
const uint8_t HEART_BODY[] PROGMEM = {
  51, 52, 53, 58, 59, 60, 66, 67, 68, 69, 70, 73, 74, 75, 76, 77, 82, 83,
  84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 98, 99, 100, 101, 102, 103, 104,
  105, 106, 107, 108, 109, 114, 115, 116, 117, 118, 119, 120, 121, 122,
  123, 124, 125, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 148,
  149, 150, 151, 152, 153, 154, 155, 165, 166, 167, 168, 169, 170, 182,
  183, 184, 185, 199, 200
};

void showHeart() {
  FastLED.clear();
  for (uint8_t i = 0; i < sizeof(HEART_BORDER); i++) {
    leds[pgm_read_byte(&HEART_BORDER[i])] = CRGB::White;
  }
  for (uint8_t i = 0; i < sizeof(HEART_BODY); i++) {
    leds[pgm_read_byte(&HEART_BODY[i])] = CRGB::Red;
  }
  FastLED.show();
}

bool readByte(uint8_t &out, unsigned long timeoutMs) {
  unsigned long start = millis();
  while (!Serial.available()) {
    if (millis() - start > timeoutMs) {
      return false;
    }
  }
  out = (uint8_t)Serial.read();
  return true;
}

bool readFrameIntoLeds() {
  // Stream RGB triples directly into leds[] to avoid a second 768-byte buffer
  // (ATmega328P only has 2KB SRAM).
  for (uint16_t i = 0; i < NUM_LEDS; i++) {
    uint8_t r, g, b;
    if (!readByte(r, 500) || !readByte(g, 500) || !readByte(b, 500)) {
      return false;
    }
    leds[i] = CRGB(r, g, b);
  }
  return true;
}

void clearMatrix() {
  FastLED.clear();
  FastLED.show();
  Serial.println(F("OK"));
}

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  Serial.begin(BAUD_RATE);
  showHeart();
}

void loop() {
  static char header[5];
  static uint8_t headerPos = 0;

  while (Serial.available()) {
    char c = (char)Serial.read();

    if (headerPos < 4) {
      header[headerPos++] = c;
      if (headerPos < 4) {
        continue;
      }
      header[4] = '\0';

      if (strcmp(header, "PX16") == 0) {
        if (readFrameIntoLeds()) {
          FastLED.show();
          Serial.println(F("OK"));
        }
        headerPos = 0;
      } else if (strcmp(header, "CLEA") == 0) {
        uint8_t trailing;
        if (readByte(trailing, 500) && trailing == 'R') {
          clearMatrix();
        }
        headerPos = 0;
      } else {
        // Resync: shift left by one and keep scanning.
        header[0] = header[1];
        header[1] = header[2];
        header[2] = header[3];
        headerPos = 3;
      }
    }
  }
}
