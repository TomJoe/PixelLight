static const byte PixelLight[] PROGMEM = {
  0xd5, //color
  20, //animDelay
  0, 7,
  0, 6,
  0, 5,
  0, 4,
  0, 3,
  0, 2,
  0, 1,
  0, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7,  0, 8, 0, 9, 0, 10, 0, 11, 0, 12, 0, 
  13, 1, 
  13, 2, 12, 2, 11, 2, 10, 2, 9, 2, 8, 2, 7, 2, 6, 2, 5, 2, 4, 2, 3, 2, 2, 2, 1, 2,

  2, 10,
  2, 11,
  2, 12,
  2, 13,
  2, 14,
  2, 15, 3, 15, 4, 15, 5, 15, 6, 15, 7, 15, 8, 15, 9, 15, 10, 15, 11, 15, 12, 15, 13, 15, 14, 15, 15, 15,
  
  COLS, ROWS //übel
};

static byte* const animations[] PROGMEM = {
  PixelLight
};

void playAnimation(int animID, int xPos, int yPos, bool clear) {

  Serial.print("Animation"); Serial.println(animID);

  if (clear) {
    for (int j = 0; j < NUM_LEDS; j++) {
      leds[j] = CRGB::Black;
    };
  };

  byte color = pgm_read_byte(pgm_read_word(&(animations[animID])));
  byte animDelay = pgm_read_byte(pgm_read_word(&(animations[animID])) + 1);

  Serial.println(color);
  Serial.println(animDelay);

  int i = 2;
  byte x = pgm_read_byte(pgm_read_word(&(animations[animID])) + i++);
  byte y = pgm_read_byte(pgm_read_word(&(animations[animID])) + i++);
  
  while (x < COLS && y < ROWS) {
    setPixel(x + xPos, y + yPos,
             CRGB(
               21 * ((color & 0xc0) >> 6) * ((color & 0x03) >> 0),
               21 * ((color & 0xc0) >> 6) * ((color & 0x0c) >> 2),
               21 * ((color & 0xc0) >> 6) * ((color & 0x30) >> 4)
             )
            );
    FastLED.show();
    delay(animDelay);
    x = pgm_read_byte(pgm_read_word(&(animations[animID])) + i++);
    y = pgm_read_byte(pgm_read_word(&(animations[animID])) + i++);
  };
};
