#include "mbed.h"

PwmOut pwm(D6);

// main() runs in its own thread in the OS
int main()
{
    float sample[10];
    sample[0] = 0.1;
    
    int cnt = 0;
    pwm.period_us(50);
    while (true) {
        for (int i = 0; i < 9; i++){
            pwm.write(0.1 + float(i) / 10);
            ThisThread::sleep_for(10ms);
        }
    }
}

