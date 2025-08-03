#include <App.h>

#if ARDUINO

void App::init() {
    randomSeed(0x12345678);

    pinMode(BUTTON, INPUT_PULLUP);

    ledMatrix.init();
}

#elif CH32V003

#include "lib_rand.h"

void App::init() {
    SystemInit();

    funGpioInitAll();

    funPinMode(BUTTON, GPIO_CNF_IN_PUPD);
    
    GpioOf(BUTTON)->OUTDR |= 1 << (BUTTON & 0xf);

    ledMatrix.init();
    seed(0x12345678);
}

#endif

bool App::updateInternal() {
    if (_buttonIsPressed) {
        return true;
    }

    ledMatrix.refreshScreen();
    if (digitalRead(BUTTON) == LOW && !_buttonIsPressed) {
        _buttonWasPressed = true;
        _buttonIsPressed = true;
    }

    return _buttonIsPressed;
}

void App::update() {
    updateInternal();

    if (digitalRead(BUTTON) == HIGH && _buttonIsPressed) {
        _buttonIsPressed = false;
    }
    _buttonWasPressed = false;
}

#if ARDUINO

void App::delay(uint32_t d) {
    unsigned long prevTime;
    unsigned long duration = 0;

    prevTime = millis();
    while (true) {
        unsigned long time = millis();
        unsigned long tmp = (time - prevTime);
        prevTime = time;
        duration += tmp;
        if (duration > d) {
            break;
        }

        if (updateInternal()) {
            break;
        }
    }
}

#elif CH32V003

void App::delay(uint32_t d) {
    uint32_t prevTime;
    uint32_t duration = 0;
    uint32_t d2 = Ticks_from_Ms(d);

    prevTime = SysTick->CNT;
    while (true) {
        uint32_t time = SysTick->CNT;
        uint32_t tmp = (time - prevTime);
        prevTime = time;
        duration += tmp;
        if (duration > d2) {
            break;
        }

        if (updateInternal()) {
            break;
        }
    }
}

#endif

#if ARDUINO

int16_t App::getRandom(int8_t minInclusive, int8_t maxExclusive) {
    return random(minInclusive, maxExclusive);
}

#elif CH32V003

int16_t App::getRandom(int8_t minInclusive, int8_t maxExclusive) {
    uint16_t d = maxExclusive - minInclusive;
    return minInclusive + rand() % d;
}

#endif

bool App::buttonWasPressed() {
    return _buttonWasPressed;
}