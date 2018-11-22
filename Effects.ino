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
      int yi = y + amp * sin8(10 * (x + i)) / 256;
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
