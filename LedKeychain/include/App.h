#ifndef _APP_H
#define _APP_H

#include <LedMatrix.h>
#include <Common.h>

class App {
    private:
    bool _buttonWasPressed;
    bool _buttonIsPressed;
    bool updateInternal();

    public:
    LedMatrix ledMatrix;

    void init();
    void delay(uint32_t delay);
    void update();
    int16_t getRandom(int8_t minInclusive, int8_t maxExclusive);
    bool buttonWasPressed();
};

#endif