#include <iostream>
#include <string>
#include "motor.h"
#include <bcm2835.h>

// PWM output on RPi Plug P1 pin 12 (which is GPIO pin 18)
// in alt fun 5.
// Note that this is the _only_ PWM pin available on the RPi IO headers
#define PIN RPI_GPIO_P1_12
// and it is controlled by PWM channel 0
#define PWM_CHANNEL 0
// This controls the max range of the PWM signal
#define RANGE 1024

DCMotorDrive::DCMotorDrive(int setDirPin1, int setDirPin2, int pwmPin)
    :setDirPin1(setDirPin1), setDirPin2(setDirPin2), pwmPin(pwmPin)
{
    // Set the output pin to Alt Fun 5, to allow PWM channel 0 to be output there
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_ALT5);
 
    // Clock divider is set to 16.
    // With a divider of 16 and a RANGE of 1024, in MARKSPACE mode,
    // the pulse repetition frequency will be
    // 1.2MHz/1024 = 1171.875Hz, suitable for driving a DC motor with PWM
    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
    bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);
    bcm2835_pwm_set_range(PWM_CHANNEL, RANGE);    
    
}

void DCMotorDrive::rotationForward(void)
{
    std::cout << "rotationForward DC motor" << std::endl;
    std::cout << "setDirPin1 = "  << this->setDirPin1 << std::endl;
    std::cout << "setDirPin2 = "  << this->setDirPin2 << std::endl;
    std::cout << "pwmPin = "  << this->pwmPin << std::endl;
}

void DCMotorDrive::rotationBack(void)
{

}

void DCMotorDrive::stop(void)
{

}

void DCMotorDrive::block(void)
{

}