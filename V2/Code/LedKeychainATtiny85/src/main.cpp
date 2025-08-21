#include <Arduino.h>
#include <LedControl.h>

#define DIN 0 // PB0
#define CS 1  // PB1
#define CLK 3 // PB3

const uint8_t ghost_Frame_1[8] PROGMEM = {0x1c, 0x3e, 0x6b, 0x49, 0x7f, 0x63, 0x7f, 0x55};
const uint8_t ghost_Frame_2[8] PROGMEM = {0x1c, 0x3e, 0x5b, 0x49, 0x7f, 0x63, 0x7f, 0x55};
const uint8_t ghost_Frame_3[8] PROGMEM = {0x1c, 0x3e, 0x49, 0x5b, 0x7f, 0x63, 0x7f, 0x55};
const uint8_t ghost_Frame_4[8] PROGMEM = {0x1c, 0x3e, 0x49, 0x6d, 0x7f, 0x63, 0x7f, 0x55};
const uint8_t ghost_Frame_5[8] PROGMEM = {0x1c, 0x3e, 0x6d, 0x49, 0x7f, 0x63, 0x7f, 0x55};
const uint8_t ghost_Frame_6[8] PROGMEM = {0x1c, 0x3e, 0x6b, 0x49, 0x7f, 0x63, 0x7f, 0x55};
const uint8_t ghost_Frame_7[8] PROGMEM = {0x1c, 0x3e, 0x6b, 0x49, 0x7f, 0x63, 0x7f, 0x55};
const uint8_t ghost_Frame_8[8] PROGMEM = {0x1c, 0x3e, 0x6b, 0x49, 0x7f, 0x63, 0x7f, 0x55};

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

LedControl lc = LedControl(DIN, CLK, CS, 1);

void displayFrame(const uint8_t *frame)
{
    for (int i = 0; i < 8; i++)
    {
        lc.setRow(0, i, pgm_read_byte(frame + i));
    }
}

void setup()
{
    lc.shutdown(0, false);
    lc.setIntensity(0, 15);
    lc.clearDisplay(0);
}

void loop()
{
    for (uint8_t i = 0; i < 6; i++)
    {
        displayFrame(ghost_frames[i]);
        delay(150);
    }
}