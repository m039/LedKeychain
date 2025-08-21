#include <Arduino.h>

// MCU: Attiny2313A

#define ROW1 0  // PD0
#define ROW2 1  // PD1
#define ROW3 2  // PA1
#define ROW4 3  // PA0
#define ROW5 4  // PD2
#define ROW6 5  // PD3
#define ROW7 6  // PD4
#define ROW8 7  // PD5

#define COLUMN1 8   // PD6
#define COLUMN2 9   // PB0
#define COLUMN3 10  // PB1
#define COLUMN4 11  // PB2
#define COLUMN5 12  // PB3
#define COLUMN6 13  // PB4
#define COLUMN7 14  // PB5
#define COLUMN8 15  // PB6

const int row[8] = {
  ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8
};

const int col[8] = {
  COLUMN1, COLUMN2, COLUMN3, COLUMN4, COLUMN5, COLUMN6, COLUMN7, COLUMN8
};

int pixels[8];

int x = 0;
int y = 0;

unsigned long prevTime;
unsigned long duration;

void setup() {
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    digitalWrite(col[thisPin], HIGH);
    digitalWrite(row[thisPin], HIGH);
  }

  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pixels[x] = pixels[x] & ~(1 << y);
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
        if (x == j && y == i) {
          pixels[j] = pixels[j] | (1 << i);
        } else {
          pixels[j] = pixels[j] & ~(1 << i);
        }
      }
    }
  }

  refreshScreen();
}

void refreshScreen() {
    for (int thisRow = 0; thisRow < 8; thisRow++) {
      digitalWrite(row[thisRow], LOW);

      for (int thisCol = 0; thisCol < 8; thisCol++) {
          int thisPixel = pixels[thisRow] & (1 << 7 - thisCol)? HIGH : LOW;
          digitalWrite(col[thisCol], thisPixel);
          if (thisPixel == HIGH) {
              digitalWrite(col[thisCol], LOW);
          }
      }

      digitalWrite(row[thisRow], HIGH);
  }
}
