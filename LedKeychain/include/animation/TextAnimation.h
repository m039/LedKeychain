#ifndef _TEXT_ANIMATION_H
#define _TEXT_ANIMATION_H

#include <animation/Animation.h>

class TextAnimation : public Animation {
    private:
    const char16_t *_text;
    unsigned long _bufferLong[14] = { 0 };

    void loadBufferLong(int unicode);
    void rotateBufferLong();
    void printBufferLong();

    public:
    virtual void animate() override;
    void init(App& app, const char16_t* text) {
        Animation::init(app);
        this->_text = text;
    }
};

#endif