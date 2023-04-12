#include "mbed.h"

PwmOut pwm(D6);

// main() runs in its own thread in the OS
int main()
{
    pwm.period_us(50);
    while (true) {

    }
}

