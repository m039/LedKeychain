#ifndef _LED_MATRIX_H
#define _LED_MATRIX_H

#include <Common.h>

const int row[8] = {
  ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8
};

const int col[8] = {
  COL1, COL2, COL3, COL4, COL5, COL6, COL7, COL8
};

const uint8_t Blank[8]= { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };

class LedMatrix {
    private:
    uint32_t _intensity;
    uint8_t _pixels[8][8];
    uint32_t _pwm;
    void invalidate();
    void refreshScreenInternal();

    public:
    void init();
    void displayFrame(const uint8_t frame[]);
    void setIntensity(uint8_t intensity);
    void refreshScreen();
};

#endif