#include <LedMatrix.h>

void LedMatrix::init() {
    for (int thisPin = 0; thisPin < 8; thisPin++) {
        PIN_MODE_OUTPUT(col[thisPin]);
        PIN_MODE_OUTPUT(row[thisPin]);
        digitalWrite(col[thisPin], LOW);
        digitalWrite(row[thisPin], HIGH);
    }

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            _pixels[x][y] = HIGH;
        }
    }
}

void LedMatrix::displayFrame(const uint8_t frame[]) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            _pixels[x][y] = frame[y] & (1 << x) ? LOW : HIGH;
        }
    }
}

void LedMatrix::invalidate() {
     _pwm = 0;
}

void LedMatrix::setIntensity(uint8_t intensity) {
    _intensity = intensity;
    invalidate();
}

void LedMatrix::refreshScreenInternal() {
    for (int thisCol = 0; thisCol < 8; thisCol++) {
        digitalWrite(col[thisCol], HIGH);

        for (int thisRow = 0; thisRow < 8; thisRow++) {
            int thisPixel = _pixels[thisCol][thisRow];
            digitalWrite(row[thisRow], thisPixel);
            if (thisPixel == LOW) {
                digitalWrite(row[thisRow], HIGH);
            }
        }

        digitalWrite(col[thisCol], LOW);
    }
}

void LedMatrix::refreshScreen() {
    _pwm++;
    if (_pwm > 16 * 16) {
        _pwm = 0;
    }

    if (_pwm < _intensity) {
        refreshScreenInternal();
    }
}