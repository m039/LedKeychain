#ifndef _ANIMATION_H
#define _ANIMATION_H

#include <App.h>

class Animation {
    protected:
    App* app;

    public:
    virtual void init(App& app) {
        this->app = &app;
    }

    virtual void animate() = 0;
};


#endif