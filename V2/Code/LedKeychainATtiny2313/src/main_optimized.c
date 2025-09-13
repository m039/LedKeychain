#if TOPTIMIZED

#include <Arduino.h>
#include <avr/io.h>

//#define ROW1 0 // PD0
//#define ROW2 5 // PD3
//#define ROW3 15 // PB6
//#define ROW4 3 // PA0
//#define ROW5 8 // PD6
//#define ROW6 14 // PB5
//#define ROW7 9 // PB0
//#define ROW8 12 // PB3

//#define COL1 4 // PD2
//#define COL2 10 // PB1
//#define COL3 11 // PB2
//#define COL4 1 // PD1
//#define COL5 13 // PB4
//#define COL6 2 // PA1
//#define COL7 6 // PD4
//#define COL8 7 // PD5

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
const uint8_t* _currentFrame;

void setRow(uint8_t index, uint8_t value) {
    switch (index) {
        case 0:
            if (value) {
                PORTD |= (1 << PD0);
            } else {
                PORTD &= ~(1 << PD0);
            }
            break;
        case 1:
            if (value) {
                PORTD |= (1 << PD3);
            } else {
                PORTD &= ~(1 << PD3);
            }
            break;
        case 2:
            if (value) {
                PORTB |= (1 << PB6);
            } else {
                PORTB &= ~(1 << PB6);
            }
            break;
        case 3:
            if (value) {
                PORTA |= (1 << PA0);
            } else {
                PORTA &= ~(1 << PA0);
            }
            break;
        case 4:
            if (value) {
                PORTD |= (1 << PD6);
            } else {
                PORTD &= ~(1 << PD6);
            }
            break;
        case 5:
            if (value) {
                PORTB |= (1 << PB5);
            } else {
                PORTB &= ~(1 << PB5);
            }
            break;
        case 6:
            if (value) {
                PORTB |= (1 << PB0);
            } else {
                PORTB &= ~(1 << PB0);
            }
            break;   
        case 7:
            if (value) {
                PORTB |= (1 << PB3);
            } else {
                PORTB &= ~(1 << PB3);
            }
            break;                         
    }
}

void setColumns(uint8_t data) {
    uint8_t portb = PORTB;
    uint8_t porta = PORTA;
    uint8_t portd = PORTD;

    if (data & (1 << 0)) {
        portd |= (1 << PD2);
    } else {
        portd &= ~(1 << PD2);
    }

    if (data & (1 << 1)) {
        portb |= (1 << PB1);
    } else {
        portb &= ~(1 << PB1);
    }

    if (data & (1 << 2)) {
        portb |= (1 << PB2);
    } else {
        portb &= ~(1 << PB2);
    }

    if (data & (1 << 3)) {
        portd |= (1 << PD1);
    } else {
        portd &= ~(1 << PD1);
    }

    if (data & (1 << 4)) {
        portb |= (1 << PB4);
    } else {
        portb &= ~(1 << PB4);
    }

    if (data & (1 << 5)) {
        porta |= (1 << PA1);
    } else {
        porta &= ~(1 << PA1);
    }

    if (data & (1 << 6)) {
        portd |= (1 << PD4);
    } else {
        portd &= ~(1 << PD4);
    }

    if (data & (1 << 7)) {
        portd |= (1 << PD5);
    } else {
        portd &= ~(1 << PD5);
    }

    PORTA = porta;
    PORTB = portb;
    PORTD = portd;
}

void displayFrame(const uint8_t* frame) {
    _currentFrame = frame;
}

void refreshScreen() {
    for (int thisRow = 0; thisRow < 8; thisRow++) {
        setRow(thisRow, 0);

        setColumns(pgm_read_byte(_currentFrame + thisRow));

        delayMicroseconds(1000);

        setColumns(0);
        setRow(thisRow, 1);
    }
}

void delayWithRefresh(unsigned long d) {
    unsigned long startTime = millis();

    while (millis() - startTime < d) {
        refreshScreen();
    }
}

void setup() {
    DDRA |= (1 << PA0) | (1 << PA1);
    DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5) | (1 << PB6);
    DDRD |= (1 << PD0) | (1 << PD1) | (1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5) | (1 << PD6);
}

void loop() {
  for (uint8_t i = 0; i < 8; i++) {
    displayFrame(ghost_frames[i]);
    delayWithRefresh(150);
  }
}

#endif