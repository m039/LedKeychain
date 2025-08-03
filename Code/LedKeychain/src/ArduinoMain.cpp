#ifdef ARDUINO

#include <stdio.h>
#include <stdlib.h>

#include <LedMatrix.h>
#include <App.h>
#include <animation/IHeartUAnimation.h>
#include <animation/DiceAnimation.h>
#include <animation/GhostAnimation.h>
#include <animation/TextAnimation.h>

App app;

uint8_t animationIndex = 0;

IHeartUAnimation iHeartUAnimation;
DiceAnimation diceAnimation;
GhostAnimation ghostAnimation;
TextAnimation textAnimation;

void setup() {
  app.init();

  iHeartUAnimation.init(app);
  diceAnimation.init(app);
  ghostAnimation.init(app);
  textAnimation.init(app, u"Привет!!! ");

  animationIndex = 0;
}

void loop() {
    if (app.buttonWasPressed()) {
      animationIndex = (animationIndex + 1) % 4;
    }

    app.update();

    switch (animationIndex) {
      case 0:
        textAnimation.animate();
        break;
      case 1:
        ghostAnimation.animate();
        break;
      case 2:
        diceAnimation.animate();
        break;
      case 3:
        iHeartUAnimation.animate();
        break;
    }
}

#endif