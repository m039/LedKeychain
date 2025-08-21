#include <Arduino.h>

// 0 - PD0
// 1 - PD1
// 2 - PA1
// 3 - PA0
// 4 - PD2
// 5 - PD3
// 6 - PD4
// 7 - PD5
// 8 - PD6
// 9 - PB0
// 10 - PB1
// 11 - PB2
// 12 - PB3
// 13 - PB4
// 14 - PB5
// 15 - PB6
// 16 - PB7
// 17 - PA2

#define COL1 0 // PD0
#define COL2 5 // PD3
#define COL3 15 // PB6
#define COL4 3 // PA0
#define COL5 8 // PD6
#define COL6 14 // PB5
#define COL7 9 // PB0
#define COL8 12 // PB3

#define ROW1 4 // PD2
#define ROW2 10 // PB1
#define ROW3 11 // PB2
#define ROW4 1 // PD1
#define ROW5 13 // PB4
#define ROW6 2 // PA1
#define ROW7 6 // PD4
#define ROW8 7 // PD5

// #define BUTTON 16 // PB7

const int row[8] = {
  ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8
};

const int col[8] = {
  COL1, COL2, COL3, COL4, COL5, COL6, COL7, COL8
};

const uint8_t ghost_Frame_1[8] PROGMEM = { 0x1c, 0x3e, 0x6b, 0x49, 0x7f, 0x63, 0x7f, 0x55 };
const uint8_t ghost_Frame_2[8] PROGMEM = { 0x1c, 0x3e, 0x5b, 0x49, 0x7f, 0x63, 0x7f, 0x55 };
const uint8_t ghost_Frame_3[8] PROGMEM = { 0x1c, 0x3e, 0x49, 0x5b, 0x7f, 0x63, 0x7f, 0x55 };
const uint8_t ghost_Frame_4[8] PROGMEM = { 0x1c, 0x3e, 0x49, 0x6d, 0x7f, 0x63, 0x7f, 0x55 };
const uint8_t ghost_Frame_5[8] PROGMEM = { 0x1c, 0x3e, 0x6d, 0x49, 0x7f, 0x63, 0x7f, 0x55 };
const uint8_t ghost_Frame_6[8] PROGMEM = { 0x1c, 0x3e, 0x6b, 0x49, 0x7f, 0x63, 0x7f, 0x55 };
const uint8_t ghost_Frame_7[8] PROGMEM = { 0x1c, 0x3e, 0x6b, 0x49, 0x7f, 0x63, 0x7f, 0x55 };
const uint8_t ghost_Frame_8[8] PROGMEM = { 0x1c, 0x3e, 0x6b, 0x49, 0x7f, 0x63, 0x7f, 0x55 };

const uint8_t *ghost_frames[8] = {
    ghost_Frame_1,
    ghost_Frame_2,
    ghost_Frame_3,
    ghost_Frame_4,
    ghost_Frame_5,
    ghost_Frame_6,
    ghost_Frame_7,
    ghost_Frame_8
};

uint8_t _pixels[8];
uint16_t _pwm;
const uint8_t _intensity = 15;

void displayFrame(const uint8_t* frame) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            uint8_t b = pgm_read_byte(frame + y);
            if (b & (1 << x)) {
                _pixels[x] = _pixels[x] | (1 << y);
            } else {
                _pixels[x] = _pixels[x] & ~(1 << y);
            }
        }
    }
}

void refreshScreen() {
    _pwm++;
    if (_pwm > 16 * 16) {
        _pwm = 0;
    }

    if (_pwm < _intensity) {
      for (int thisRow = 0; thisRow < 8; thisRow++) {
        digitalWrite(row[thisRow], LOW);

        for (int thisCol = 0; thisCol < 8; thisCol++) {
            int thisPixel;

            if (_pixels[thisCol] & (1 << thisRow)) {
                thisPixel = HIGH;
            } else {
                thisPixel = LOW;
            }

            digitalWrite(col[thisCol], thisPixel);
            if (thisPixel == HIGH) {
                digitalWrite(col[thisCol], LOW);
            }
        }

        digitalWrite(row[thisRow], HIGH);
      }
    }
}

void delayWithRefresh(unsigned long d) {
    unsigned long prevTime = millis();
    unsigned long duration = 0;

    while (true) {
        unsigned long time = millis();
        unsigned long tmp = (time - prevTime);
        prevTime = time;
        duration += tmp;
        if (duration > d) {
            break;
        }

        refreshScreen();
    }
}

void setup() {
  for (int thisPin = 0; thisPin < 8; thisPin++) {
      pinMode(col[thisPin], OUTPUT);
      pinMode(row[thisPin], OUTPUT);
      digitalWrite(col[thisPin], LOW);
      digitalWrite(row[thisPin], HIGH);
  }

  for (int x = 0; x < 8; x++) {
      for (int y = 0; y < 8; y++) {
          _pixels[x] = _pixels[x] | (1 << y);
      }
  }
}

void loop() {
  for (uint8_t i = 0; i < 8; i++) {
    displayFrame(ghost_frames[i]);
    delayWithRefresh(150);
  }
}