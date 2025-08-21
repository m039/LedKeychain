#ifndef _COMMON_H
#define _COMMON_H

#if ATMEGA328

#include <Arduino.h>

#define COL1 0  // D0
#define COL2 1  // D1
#define COL3 2  // D2
#define COL4 3  // D3
#define COL5 4  // D4
#define COL6 5  // D5
#define COL7 6  // D6
#define COL8 7  // D7

#define ROW1 8   // B0
#define ROW2 9   // B1
#define ROW3 10  // B2
#define ROW4 11  // B3
#define ROW5 12  // B4
#define ROW6 13  // B5
#define ROW7 14  // C0
#define ROW8 15  // C1

#define BUTTON 16 // C2

#define PIN_MODE_OUTPUT(pin) pinMode(pin, OUTPUT)

#elif ATTINY2313

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

#define BUTTON 16 // PB7

#define PIN_MODE_OUTPUT(pin) pinMode(pin, OUTPUT)

#elif CH32V003

#include <ch32fun.h>

#define BUTTON PC1

#define COL1 PA1
#define COL2 PC4
#define COL3 PC5
#define COL4 PD5
#define COL5 PC7
#define COL6 PD6
#define COL7 PD0
#define COL8 PC0

#define ROW1 PD4
#define ROW2 PA2
#define ROW3 PD3
#define ROW4 PD7
#define ROW5 PC2
#define ROW6 PD2
#define ROW7 PC3
#define ROW8 PC6

#define HIGH FUN_HIGH

#define LOW FUN_LOW

#define digitalWrite(pin, value) funDigitalWrite(pin, value)
#define digitalRead(pin) funDigitalRead(pin)

#define PIN_MODE_OUTPUT(pin) funPinMode(pin, GPIO_Speed_10MHz | GPIO_CNF_OUT_PP)

#endif
#endif