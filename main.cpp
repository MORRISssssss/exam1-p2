#include "mbed.h"

PwmOut pwm(D6);
AnalogIn ain(A0);

Thread t;

void ADC()
{
    float v;
    float sample[1000];
    for (int i = 0; i < 1000; i++){
        sample[i] = ain.read();
        ThisThread::sleep_for(1ms);
    }
    for (int i = 0; i < 1000; i++){
        printf("%d: %f\n", i, sample[i]);
    }
    while (true){
        ;
    }
}

// main() runs in its own thread in the OS
int main()
{
    t.start(ADC);
    pwm.period_us(50);
    while (true) {
        for (int i = 0; i < 9; i++){
            pwm.write(0.1 + float(i) / 10);
            ThisThread::sleep_for(10ms);
        }
    }
}

