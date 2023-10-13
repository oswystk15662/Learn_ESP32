/*
this class provide 10 bits background pwm function.
*/

#pragma once

#include <Arduino.h>

typedef uint8_t PinName;

class PwmOut{
private:
    PinName pin;
    int freq = 50;
    uint8_t ch;
    const int resolution_bits = 10;
    float duty;

public:
    PwmOut(PinName _pin, uint8_t _ch);
    
    void operator=(float _duty);

    void write(float _duty);
    void period(float _period_s);
    void period_ms(unsigned int _period_ms);
    void period_us(unsigned int _period_us);
    void suspend();
    void resume();
};