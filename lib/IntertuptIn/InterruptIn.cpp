#include <InterruptIn.hpp>

InterruptIn::InterruptIn(PinName _pin):pin(_pin)
{
    pinMode(pin, INPUT_PULLUP);
    attachInterrupt(pin, rise, RISING);
    attachInterrupt(pin, fall, FALLING);
}

InterruptIn::InterruptIn(PinName _pin, mPinMode _mpm):pin(_pin)
{
    pinMode(pin, INPUT_PULLUP);
}

void InterruptIn::rise(function<void()> _func){
    detachInterrupt(pin);
    _func();

    attachInterrupt(pin, rise, RISING);
}

void InterruptIn::fall(function<void()> _func){
    detachInterrupt(pin);
    _func();

    attachInterrupt(pin, fall, FALLING);
}