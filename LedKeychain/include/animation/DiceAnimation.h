#ifndef _DICE_ANIMATION_H
#define _DICE_ANIMATION_H

#include <animation/Animation.h>

class DiceAnimation : public Animation {
    public:
    virtual void animate() override;
};

#endif