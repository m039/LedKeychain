#include <animation/IHeartUAnimation.h>

const int SPEED_1 = 40;
const int SPEED_2 = 40;
const int SPEED_3 = 500;

uint8_t I[8]= {0x7e,0x18,0x18,0x18,0x18,0x18,0x18,0x7e};
uint8_t Heart_1[8]= {0x6C,0xFE,0xFE,0xFE,0x7C,0x38,0x10,0x00};
uint8_t Heart_2[8]= {0x00,0x36,0x7F,0x7F,0x7F,0x3E,0x1C,0x08};
uint8_t U[8]= {0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xFF,0x7E};
uint8_t Trans_1[8]= {0xaa,0x55,0xaa,0x55,0xaa,0x55,0xaa,0x55};
uint8_t Trans_2[8]= {0x55,0xaa,0x55,0xaa,0x55,0xaa,0x55,0xaa};
uint8_t Heart_Frame_1[8]= {0x0,0x36,0x49,0x41,0x41,0x22,0x14,0x8};
uint8_t Heart_Frame_2[8]= {0x0,0x36,0x49,0x41,0x41,0x22,0x1c,0x8};
uint8_t Heart_Frame_3[8]= {0x0,0x36,0x49,0x41,0x41,0x32,0x1c,0x8};
uint8_t Heart_Frame_4[8]= {0x0,0x36,0x49,0x41,0x41,0x3a,0x1c,0x8};
uint8_t Heart_Frame_5[8]= {0x0,0x36,0x49,0x41,0x41,0x3e,0x1c,0x8};
uint8_t Heart_Frame_6[8]= {0x0,0x36,0x49,0x41,0x43,0x3e,0x1c,0x8};
uint8_t Heart_Frame_7[8]= {0x0,0x36,0x49,0x41,0x47,0x3e,0x1c,0x8};
uint8_t Heart_Frame_8[8]= {0x0,0x36,0x49,0x41,0x4f,0x3e,0x1c,0x8};
uint8_t Heart_Frame_9[8]= {0x0,0x36,0x49,0x41,0x5f,0x3e,0x1c,0x8};
uint8_t Heart_Frame_10[8]= {0x0,0x36,0x49,0x41,0x7f,0x3e,0x1c,0x8};
uint8_t Heart_Frame_11[8]= {0x0,0x36,0x49,0x61,0x7f,0x3e,0x1c,0x8};
uint8_t Heart_Frame_12[8]= {0x0,0x36,0x49,0x71,0x7f,0x3e,0x1c,0x8};
uint8_t Heart_Frame_13[8]= {0x0,0x36,0x49,0x79,0x7f,0x3e,0x1c,0x8};
uint8_t Heart_Frame_14[8]= {0x0,0x36,0x49,0x7d,0x7f,0x3e,0x1c,0x8};
uint8_t Heart_Frame_15[8]= {0x0,0x36,0x49,0x7f,0x7f,0x3e,0x1c,0x8};
uint8_t Heart_Frame_16[8]= {0x0,0x36,0x4b,0x7f,0x7f,0x3e,0x1c,0x8};
uint8_t Heart_Frame_17[8]= {0x0,0x36,0x4f,0x7f,0x7f,0x3e,0x1c,0x8};
uint8_t Heart_Frame_18[8]= {0x0,0x36,0x5f,0x7f,0x7f,0x3e,0x1c,0x8};
uint8_t Heart_Frame_19[8]= {0x0,0x36,0x7f,0x7f,0x7f,0x3e,0x1c,0x8};

void IHeartUAnimation::iAnimation() {
  for (int i = 0; i <= 15; i++) {
    app->ledMatrix.displayFrame(I);
    app->ledMatrix.setIntensity(i);
    app->delay(SPEED_1);
  }
  app->delay(500);

  for (int i = 15; i >= 0; i--) {
    app->ledMatrix.displayFrame(I);
    app->ledMatrix.setIntensity(i);
    app->delay(SPEED_1);
  }
  app->ledMatrix.displayFrame(Blank);
  app->ledMatrix.setIntensity(0);
  app->delay(SPEED_1);
}

void IHeartUAnimation::transition() {
  app->ledMatrix.displayFrame(Trans_1);
  app->ledMatrix.setIntensity(15);
  app->delay(SPEED_2);

  app->ledMatrix.displayFrame(Trans_2);
  app->ledMatrix.setIntensity(15);
  app->delay(SPEED_2);

  app->ledMatrix.displayFrame(Trans_1);
  app->ledMatrix.setIntensity(15);
  app->delay(SPEED_2);

  app->ledMatrix.displayFrame(Trans_2);
  app->ledMatrix.setIntensity(15);
  app->delay(SPEED_2);

  app->ledMatrix.displayFrame(Trans_1);
  app->ledMatrix.setIntensity(15);
  app->delay(SPEED_2);

  app->ledMatrix.displayFrame(Trans_2);
  app->ledMatrix.setIntensity(15);
  app->delay(SPEED_2);

  app->ledMatrix.displayFrame(Trans_1);
  app->ledMatrix.setIntensity(15);
  app->delay(SPEED_2);

  app->ledMatrix.displayFrame(Trans_2);
  app->ledMatrix.setIntensity(15);
  app->delay(SPEED_2);

  app->ledMatrix.displayFrame(Trans_1);
  app->ledMatrix.setIntensity(15);
  app->delay(SPEED_2);

  app->ledMatrix.displayFrame(Trans_2);
  app->ledMatrix.setIntensity(15);
  app->delay(SPEED_2);
}

void IHeartUAnimation::heartBeat() {
  app->ledMatrix.displayFrame(Heart_2);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_3);

  app->ledMatrix.displayFrame(Heart_1);
  app->ledMatrix.setIntensity(15);
  app->delay(SPEED_2);

  app->ledMatrix.displayFrame(Heart_2);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_2);

  app->ledMatrix.displayFrame(Heart_1);
  app->ledMatrix.setIntensity(15);
  app->delay(SPEED_2);

  app->ledMatrix.displayFrame(Heart_2);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_2);
}

void IHeartUAnimation::heartAnimation() {
  app->ledMatrix.displayFrame(Heart_Frame_1);
  app->ledMatrix.setIntensity(1);
  app->delay(300);

  app->ledMatrix.displayFrame(Heart_Frame_2);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_3);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_4);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_5);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_6);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_7);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_8);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_9);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_10);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_11);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_12);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_13);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_14);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_15);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_16);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_17);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_18);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);

  app->ledMatrix.displayFrame(Heart_Frame_19);
  app->ledMatrix.setIntensity(1);
  app->delay(SPEED_1);
}

void IHeartUAnimation::uAnimation() {
  for (int i = 0; i <= 15; i++) {
    app->ledMatrix.displayFrame(U);
    app->ledMatrix.setIntensity(i);
    app->delay(SPEED_1);
  }
  app->delay(500);
}


void IHeartUAnimation::animate() {
    transition();

    iAnimation();

    heartAnimation();

    heartBeat();
    heartBeat();
    heartBeat();

    app->delay(SPEED_2);

    for (int i = 1; i <= 15; i++) {
      app->ledMatrix.displayFrame(Heart_2);
      app->ledMatrix.setIntensity(i);
      app->delay(SPEED_1);
    }

    app->delay(SPEED_3);

    for (int i = 15; i >= 0; i--) {
      app->ledMatrix.displayFrame(Heart_2);
      app->ledMatrix.setIntensity(i);
      app->delay(SPEED_1);
    }

    app->ledMatrix.displayFrame(Blank);
    app->ledMatrix.setIntensity(0);
    app->delay(SPEED_1);

    uAnimation();
}