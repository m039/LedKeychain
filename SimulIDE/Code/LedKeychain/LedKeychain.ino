#include <Arduino.h>

#define COLUMN1 0  // D0
#define COLUMN2 1  // D1
#define COLUMN3 2  // D2
#define COLUMN4 3  // D3
#define COLUMN5 4  // D4
#define COLUMN6 5  // D5
#define COLUMN7 6  // D6
#define COLUMN8 7  // D7

#define ROW1 8   // B0
#define ROW2 9   // B1
#define ROW3 10  // B2
#define ROW4 11  // B3
#define ROW5 12  // B4
#define ROW6 13  // B5
#define ROW7 14  // C0
#define ROW8 15  // C1

const int row[8] = {
  ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8
};

const int col[8] = {
  COLUMN1, COLUMN2, COLUMN3, COLUMN4, COLUMN5, COLUMN6, COLUMN7, COLUMN8
};

int pixels[8][8];

int x = 0;
int y = 0;

unsigned long prevTime;
unsigned long duration;

void setup() {
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    digitalWrite(col[thisPin], LOW);
    digitalWrite(row[thisPin], HIGH);
  }

  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pixels[x][y] = HIGH;
    }
  }

  prevTime = millis();
}

void loop() {
  unsigned long t = millis();
  duration += (t - prevTime);
  prevTime = t;
  if (duration > 100) {
    duration = 0;

    x += 1;
    if (x >= 8) {
      x = 0;
      y += 1;
      if (y >= 8) {
        y = 0;
      }
    }

    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        pixels[i][j] = x == j && y == i ? LOW : HIGH;
      }
    }
  }

  refreshScreen();
}

void refreshScreen() {
  for (int thisCol = 0; thisCol < 8; thisCol++) {
    digitalWrite(col[thisCol], HIGH);

    for (int thisRow = 0; thisRow < 8; thisRow++) {
      int thisPixel = pixels[thisCol][thisRow];
      digitalWrite(row[thisRow], thisPixel);
      if (thisPixel == LOW) {
        digitalWrite(row[thisRow], HIGH);
      }
    }

    digitalWrite(col[thisCol], LOW);
  }
}
