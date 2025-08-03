#ifndef _GHOST_ANIMATION_H
#define _GHOST_ANIMATION_H

#include <animation/Animation.h>

class GhostAnimation : public Animation {
    public:
    virtual void animate() override;
};

#endif