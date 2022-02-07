#include <wiringPi.h>
#include <bcm2835.h>
#include "hardware.h"

hardware* hardware::getInstance()
{
    static hardware instance;
    return &instance;    
}

hardware::hardware() 
{
    this->stateHardwareInit = true;
    if (!bcm2835_init())
    {
        this->stateHardwareInit = false;
        return;    
    }

    if (wiringPiSetup() == -1)
    {
        this->stateHardwareInit = false;
        return;    
    }
}

bool hardware::isHardwareInit()
{
    return this->stateHardwareInit;
}

