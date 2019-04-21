#include <FastLED.h>

//toDO
//HardwareSPI
// Use Brigten


#define BLK CRGB::Black
#define WHT CRGB::White
#define RED CRGB::Red
#define GRN CRGB::Green
#define BLU CRGB::Blue

#define CLEAR fillPanel(BLK)
#define SHOW FastLED.show()
#define PRNT Serial.print
#define PRLN Serial.println
#define PRSL Serial.print("/")
#define DELY delay(aDelay)

// How many leds in your strip?
#define NUM_LEDS 256

#define DATA_PIN 4
#define CLOCK_PIN 5

#define COLS 16
#define ROWS 16

// Define the array of leds
CRGB leds[NUM_LEDS];


void setup() {

  FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
  FastLED.setCorrection( TypicalSMD5050 );
  FastLED.setBrightness( 32 );

  Serial.begin(115000);

  for (int j = 0; j < NUM_LEDS; j++) {

    leds[j] = CRGB::Blue;
  }
  FastLED.show();
  delay(100);
  for (int j = 0; j < NUM_LEDS; j++) {

    leds[j] = CRGB::Red;
  }
  FastLED.show();
  delay(100);

  for (int j = 0; j < NUM_LEDS; j++) {

    leds[j] = CRGB::Green;
  }
  FastLED.show();
  delay(100);

  for (int j = 0; j < NUM_LEDS; j++) {

    leds[j] = CRGB::Black;
  }
  SHOW;

  playScript(16);
  playScript(3);

}

void loop() {

  playScript(random8(6, 18));
  playScript(random8(0, 5));

}

int xyToLED(int x, int y) {


  y = max(0, min(ROWS, y));
  x = max(0, min(COLS, x));


  int pixel;

  
  
  if (y % 2 == 0)
  {
    pixel = y * ROWS + x;
  } else {
    pixel = (y + 1) * ROWS - x - 1;
  }

  if (y >= 6) pixel--;
  return pixel;
}

void setPixel(int x, int y, CRGB color) {

  if (x >= 0 && x < COLS && y >= 0 && y < ROWS) {

    leds[xyToLED(x, y)] = color;

  }
}
