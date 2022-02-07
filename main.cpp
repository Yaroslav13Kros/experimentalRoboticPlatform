#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "motor.h"
#include <bcm2835.h>
#include "hardware.h"
#include <vector>

int main()
{
    if(hardware::getInstance()->isHardwareInit())
    {
        MotorDriver* motor1 = new DCMotorDrive(1, 2, 3);
        motor1->rotationForward();
        delete motor1;
    }

    return EXIT_SUCCESS;
}