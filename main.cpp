#include "mbed.h"

PwmOut pwm(D6);
AnalogIn ain(A0);

Thread t;
Thread queueThread;
EventQueue queue(32 * EVENTS_EVENT_SIZE);

void ADC()
{
    float v;
    while (true){
        v = ain.read();
        queue.call(printf, "%f\n", v);
        ThisThread::sleep_for(1ms);
    }
}

// main() runs in its own thread in the OS
int main()
{
    t.start(ADC);
    queueThread.start(callback(&queue, &EventQueue::dispatch_forever));
    pwm.period_us(50);
    while (true) {
        for (int i = 0; i < 9; i++){
            pwm.write(0.1 + float(i) / 10);
            ThisThread::sleep_for(10ms);
        }
    }
}

