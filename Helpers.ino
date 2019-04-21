

void debug(float x, float y, float i) {
  Serial.print("x:"); Serial.println(x);
  Serial.print("y:"); Serial.println(y);
  Serial.print("i:"); Serial.println(i);
}

void fillToTop(int x, int y, CRGB color) {
  for (; y >= 0; y--) {
    setPixel(x, y, color);
  }
}

void fillToLeft(int x, int y, CRGB color) {
  for (; x >= 0; x--) {
    setPixel(x, y, color);
  }
}

void fillToBottom(int x, int y, CRGB color) {
  for (; y < ROWS; y++) {
    setPixel(x, y, color);
  }
}

void fillToRight(int x, int y, CRGB color) {
  for (; x < COLS; x++) {
    setPixel(x, y, color);
  }
}


void fillPanel(CRGB color) {
  for (int j = 0; j < NUM_LEDS; j++) {
    leds[j] = color;
  };
}

void drawHorzLine(int x, CRGB color) {
  for (int y = 0; y < COLS; y++) {
    setPixel(x, y, color);
  }
};

void drawVertLine(int y, CRGB color) {
  for (int x = 0; x < ROWS; x++) {
    setPixel(x, y, color);
  }
};

void drawLine(int xStart, int yStart, int xEnd, int yEnd, CRGB color) {
  int stepsNeeded = max(abs8(yEnd - yStart), abs8(xEnd - xStart));
  PRLN(stepsNeeded);
  int x, y;
  for (int i = 0; i <= stepsNeeded; i++) {
    x = lerp8by8(xStart, xEnd, 255 * i / stepsNeeded);
    y = lerp8by8(yStart, yEnd, 255 * i / stepsNeeded);
    PRNT(x); PRNT("/"); PRLN(y);
    setPixel(x, y, color);
  };
}

void drawCircle(int x0, int y0, int radius, CRGB color) {
  int x = radius - 1;
  int y = 0;
  int dx = 1;
  int dy = 1;
  int err = dx - (radius << 1);

  while (x >= y)
  {
    setPixel(x0 + x, y0 + y, color);
    setPixel(x0 + y, y0 + x, color);
    setPixel(x0 - y, y0 + x, color);
    setPixel(x0 - x, y0 + y, color);
    setPixel(x0 - x, y0 - y, color);
    setPixel(x0 - y, y0 - x, color);
    setPixel(x0 + y, y0 - x, color);
    setPixel(x0 + x, y0 - y, color);

    if (err <= 0)
    {
      y++;
      err += dy;
      dy += 2;
    }

    if (err > 0)
    {
      x--;
      dx += 2;
      err += dx - (radius << 1);
    }
  }
}

void fillCircle(int x, int y, int r, CRGB color) {
  for (int xi = 0; xi < r; xi++) {
    for (int yi = 0; yi < r; yi++) {
      if ((r * r) >= ((xi * xi) + (yi * yi))) {
        setPixel(x+xi, y+yi, color);
        setPixel(x-xi, y-yi, color);
        setPixel(x+xi, y-yi, color);
        setPixel(x-xi, y+yi, color);
      }
    }
  }
}

float schwimmenderRandolph(){
  return (float) random(-100, 100) / 100.0;
}
