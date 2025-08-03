#ifndef _I_HEART_U_ANIMATION_H
#define _I_HEART_U_ANIMATION_H

#include <animation/Animation.h>

class IHeartUAnimation : public Animation {
    private: 
    void iAnimation();
    void transition();
    void heartBeat();
    void heartAnimation();
    void uAnimation();

    public:
    virtual void animate() override;
};

#endif