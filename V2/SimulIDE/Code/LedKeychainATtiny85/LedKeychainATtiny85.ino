#include <Arduino.h>

#define DIN 0 // PB0
#define CS 1 // PB1
#define CLK 3 // PB3

#include <LedControl.h>

// MCU: Attiny85

int pixels[8];

int x = 0;
int y = 0;

unsigned long prevTime;
unsigned long duration;

LedControl lc = LedControl(DIN, CLK, CS, 1);

void setup() {
  lc.shutdown(0,false);       
  lc.setIntensity(0,15);
  lc.clearDisplay(0);  

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

    refreshScreen();
  }
}

void refreshScreen() {
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0, i, pixels[i]);
  }
}
