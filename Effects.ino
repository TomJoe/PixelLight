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

void ratator(int aDelay) {
  for (int x = 0; x < COLS; x++) {
    CLEAR;
    drawLine(x, 0, COLS - x, ROWS - 1, GRN);
    SHOW;
    delay(aDelay);
  }
  for (int y = 0; y < ROWS; y++) {
    CLEAR;
    drawLine(COLS - 1, y, 0, ROWS - y, GRN);
    SHOW;
    delay(aDelay);
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
    fillCircle(xi, yi, i, RED);
    SHOW;
    DELY;
  }
  xi = random8(16);
  yi = random8(16);
  for (int i = 0; i < 20; i++) {
    fillCircle(xi, yi,  i, GRN);
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

void tunnel(int aDelay) {


  int j = 32;
  while (j > 0) {
    CLEAR;
    int xj = COLS*(sin8_avr(j * 10) - 128)/128;
    int yj = ROWS*(cos8(j * 10) - 128)/128;
    PRNT(xj); PRSL;PRNT(yj); PRSL;PRLN(j);
    int i = 16;
    
    while (i > 0) {
      int x = xj  + i / 2;
      int y = xj  + i / 2;
      int r = i;
      CRGB color = blend(BLK, RED, 256 * i / 16);
      drawCircle(x, y, r, color);
      i--;
    }
   
    SHOW;
    DELY;
    j--;
  }
}

void effectWipe(int mode, int tail, int yPos, bool clear, int aDelay) {
  Serial.print("delay: "); Serial.println(aDelay);
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
