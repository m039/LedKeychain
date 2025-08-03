#include <animation/DiceAnimation.h>

const int max_bright = 5;

const int SPEED_1 = 15;
const int SPEED_2 = 500;
const int SPEED_3 = 2000;
const int SPEED_4 = 40;
const int SPEED_5 = 60;
const int SPEED_6 = 500;
const int SPEED_0 = 0;

uint8_t dice_Frame_1[8] = {0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00};
uint8_t dice_Frame_2[8] = {0x00, 0x60, 0x60, 0x00, 0x00, 0x06, 0x06, 0x00};
uint8_t dice_Frame_3[8] = {0xc0, 0xc0, 0x00, 0x18, 0x18, 0x00, 0x03, 0x03};
uint8_t dice_Frame_4[8] = {0x00, 0x66, 0x66, 0x00, 0x00, 0x66, 0x66, 0x00};
uint8_t dice_Frame_5[8] = {0xc3, 0xc3, 0x00, 0x18, 0x18, 0x00, 0xc3, 0xc3};
uint8_t dice_Frame_6[8] = {0x66, 0x66, 0x00, 0x66, 0x66, 0x00, 0x66, 0x66};

void DiceAnimation::animate()
{
    int8_t r = app->getRandom(1, 7);
    if (r == 1)
    {
        for (int i = 1; i <= max_bright; i++)
        {
            app->ledMatrix.displayFrame(dice_Frame_1);
            app->ledMatrix.setIntensity(i);
            app->delay(SPEED_5);
        }
        for (int i = max_bright; i >= 0; i--)
        {
            app->ledMatrix.displayFrame(dice_Frame_1);
            app->ledMatrix.setIntensity(i);
            app->delay(SPEED_5);
        }
    }
    else if (r == 2)
    {
        for (int i = 1; i <= max_bright; i++)
        {
            app->ledMatrix.displayFrame(dice_Frame_2);
            app->ledMatrix.setIntensity(i);
            app->delay(SPEED_5);
        }
        for (int i = max_bright; i >= 0; i--)
        {
            app->ledMatrix.displayFrame(dice_Frame_2);
            app->ledMatrix.setIntensity(i);
            app->delay(SPEED_5);
        }
    }
    else if (r == 3)
    {
        for (int i = 1; i <= max_bright; i++)
        {
            app->ledMatrix.displayFrame(dice_Frame_3);
            app->ledMatrix.setIntensity(i);
            app->delay(SPEED_5);
        }
        for (int i = max_bright; i >= 0; i--)
        {
            app->ledMatrix.displayFrame(dice_Frame_3);
            app->ledMatrix.setIntensity(i);
            app->delay(SPEED_5);
        }
    }
    else if (r == 4)
    {
        for (int i = 1; i <= max_bright; i++)
        {
            app->ledMatrix.displayFrame(dice_Frame_4);
            app->ledMatrix.setIntensity(i);
            app->delay(SPEED_5);
        }
        for (int i = max_bright; i >= 0; i--)
        {
            app->ledMatrix.displayFrame(dice_Frame_4);
            app->ledMatrix.setIntensity(i);
            app->delay(SPEED_5);
        }
    }
    else if (r == 5)
    {
        for (int i = 1; i <= max_bright; i++)
        {
            app->ledMatrix.displayFrame(dice_Frame_5);
            app->ledMatrix.setIntensity(i);
            app->delay(SPEED_5);
        }
        for (int i = max_bright; i >= 0; i--)
        {
            app->ledMatrix.displayFrame(dice_Frame_5);
            app->ledMatrix.setIntensity(i);
            app->delay(SPEED_5);
        }
    }
    else if (r == 6)
    {
        for (int i = 1; i <= max_bright; i++)
        {
            app->ledMatrix.displayFrame(dice_Frame_6);
            app->ledMatrix.setIntensity(i);
            app->delay(SPEED_5);
        }
        for (int i = max_bright; i >= 0; i--)
        {
            app->ledMatrix.displayFrame(dice_Frame_6);
            app->ledMatrix.setIntensity(i);
            app->delay(SPEED_5);
        }
    }
    app->delay(SPEED_6);
}