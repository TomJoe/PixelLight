DEFINE_GRADIENT_PALETTE( heatmap_gp ) {
  0,     0,  0,  0,   //black
  128,   255,  0,  0,   //red
  224,   255, 255,  0,  //bright yellow
  255,   255, 255, 255
}; //full white

DEFINE_GRADIENT_PALETTE( red_to_white_gp ) {
  0,     255,  255, 255,
  128,   255,    0,   0,
  255,     0,    0,   0
}; //full white

DECLARE_GRADIENT_PALETTE( Rainbow_gp);

void striperRight(int aDelay, int tail) {
  for (int x = 0; x < ROWS + tail; x++) {
    CLEAR;
    for (int i = 0; i < tail; i++) {
      drawHorzLine(x - i, blend(RED, BLK, 256 * i / tail));
    };
    drawHorzLine(x, WHT);
    SHOW;
    delay(aDelay);
  }
};

void striperUp(int aDelay, int tail) {
  Serial.print("up:"); Serial.println(tail);
  for (int y = 0; y < ROWS + tail; y++) {
    CLEAR;
    for (int i = 0; i < tail; i++) {
      drawVertLine(y - i, blend(RED, BLK, 256 * i / tail));
    };
    drawVertLine(y, WHT);
    SHOW;
    delay(aDelay);
  }
};

void striperLeft(int aDelay, int tail) {
  for (int x = ROWS - 1; x >= 0 - tail; x--) {
    CLEAR;
    for (int i = 0; i < tail; i++) {
      drawHorzLine(x + i, blend(RED, BLK, 256 * i / tail));
    };
    drawHorzLine(x, WHT);
    SHOW;
    delay(aDelay);
  }
};

void striperDown(int aDelay, int tail) {
  for (int y = ROWS - 1; y >= 0 - tail; y--) {
    CLEAR;
    for (int i = 0; i < tail; i++) {
      drawVertLine(y + i, blend(RED, BLK, 256 * i / tail));
    };
    drawVertLine(y, WHT);
    SHOW;
    delay(aDelay);
  }
};

void sinSplitHorz(int aDelay, int amp, int y) {
  for (int i = 0; i < 250; i++) {
    for (int x = 0; x < COLS; x++) {
      int yi = y + amp * (sin8(10 * (x + i)) + sin8(15 * (x - i)) + sin8(17 * (x + 1 ))) / 1024;
      fillToTop(x, yi, RED);
      fillToBottom(x, yi + 1, BLU);
    }
    SHOW;
    delay(aDelay);
  }
};

void ratator(int aDelay, int tail, int len) {

  CRGBPalette16 myPal = Rainbow_gp;

  int i = len;
  while (i > 0) {
    CLEAR;
    for (int j = tail; j > 0; j--) {
      int x = COLS / 2 - 1 + (sin8(j * 7 + i * 5) - 128) / 16;
      drawLine(x, 0, COLS - x, ROWS - 1, ColorFromPalette( myPal, 255 - (j * (255 / tail))));
    }
    SHOW;
    DELY;
    i--;
  }
}

void bloob(bool clear, int aDelay) {
  if (clear) {
    fillPanel(WHT);
    SHOW;
    DELY;
  };
  int xi = random8(16);
  int yi = random8(16);
  for (int i = 0; i < 20; i++) {
    fillCircle(xi, yi, i, GRN);
    SHOW;
    DELY;
  }
  xi = random8(16);
  yi = random8(16);
  for (int i = 0; i < 20; i++) {
    fillCircle(xi, yi,  i, RED);
    SHOW;
    DELY;
  }
  xi = random8(16);
  yi = random8(16);
  for (int i = 0; i < 20; i++) {
    fillCircle(xi, yi, i, BLU);
    SHOW;
    DELY;
  }
}

void dropSprite(int aDelay, int spriteID) {

}

void tunnel(int aDelay) {

  CRGBPalette16 myPal = red_to_white_gp;

  int j = 64;
  while (j > 0) {
    CLEAR;

    int i = 16;

    while (i > 0) {
      int x = COLS / 2 - 1 + (sin8(j * 14) - 128) * (16 - i) / 256;
      int y = ROWS / 2 - 1 + (cos8(j * 8) - 128) * (16 - i) / 256;
      int r = i;
      PRNT(x); PRSL; PRNT(y); PRSL; PRLN(r);
      CRGB color = ColorFromPalette( myPal, (16 - i) * 16);
      fillCircle(x, y, r, color);
      i--;
    }

    SHOW;
    DELY;
    j--;
  }
}

struct star {
  int frame;
  float xx;
  float yy;
};

#define FEINUNG 10.0
#define NUMSTARS 30
#define ITERS 400
#define LIGHT 5



void starField(int aDelay) {
  FastLED.setBrightness( 255 );

  star stars[NUMSTARS];
  for (int i = NUMSTARS-1; i >= 0; i--) {
    stars[i].xx = schwimmenderRandolph();
    stars[i].yy = schwimmenderRandolph();
  }

  for (int j = 0; j < ITERS; j++) {
    for (int jj = 0; jj < NUM_LEDS; jj++) {
      leds[jj] = CRGB::Black;
    };
    int x,y;
    CRGB starColor;
    for (int i = NUMSTARS-1; i >= 0; i--) {
      
      long state = stars[i].frame * stars[i].frame;
      x = 8 + state * stars[i].xx / FEINUNG;
      y = 8 + state * stars[i].yy / FEINUNG;
      starColor = CRGB(state/LIGHT,state/LIGHT,state/LIGHT);
      
      stars[i].frame++;
      
      setPixel(x,y, starColor);
      if ((x > COLS || x < 0) && ((y > ROWS || y < 0))){
        stars[i].xx = schwimmenderRandolph();
        stars[i].yy = schwimmenderRandolph();
        stars[i].frame = 0;
      }
    }
    SHOW;
    DELY;
  }
  FastLED.setBrightness( MAX_BREIT );
}

void effectWipe(int mode, int tail, int yPos, bool clear, int aDelay) {
  switch (mode) {
    case 0:
      striperRight(aDelay, tail);
      break;
    case 1:
      striperLeft(aDelay, tail);
      break;
    case 2:
      striperUp(aDelay, tail);
      break;
    case 3:
      striperDown(aDelay, tail);
      break;
  }
}
