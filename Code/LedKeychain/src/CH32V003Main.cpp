#if defined(CH32V003) && !defined(ARDUINO)

#include <stdio.h>
#include <stdlib.h>

#include <LedMatrix.h>
#include <App.h>
#include <animation/IHeartUAnimation.h>
#include <animation/DiceAnimation.h>
#include <animation/GhostAnimation.h>
#include <animation/TextAnimation.h>

App app;

IHeartUAnimation iHeartUAnimation;
DiceAnimation diceAnimation;
GhostAnimation ghostAnimation;
TextAnimation textAnimation;

uint8_t animationIndex = 0;

int main() {	
  app.init();

  iHeartUAnimation.init(app);
  diceAnimation.init(app);
  ghostAnimation.init(app);
  textAnimation.init(app, u"Привет!!! ");

  animationIndex = 1;

  while (true) {
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
}
#endif