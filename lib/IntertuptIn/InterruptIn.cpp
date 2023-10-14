#include <InterruptIn.hpp>

InterruptIn::InterruptIn(PinName _pin):pin(_pin)
{
    pinMode(pin, INPUT_PULLUP);
    attachInterrupt(pin, [this]{risefunc();}, RISING);
    attachInterrupt(pin, [this]{fallfunc();}, FALLING);
}

InterruptIn::InterruptIn(PinName _pin, mPinMode _mpm):pin(_pin)
{
    pinMode(pin, INPUT_PULLUP);
}

void InterruptIn::rise(function<void()> _func){
    risefunc = _func;
}

void InterruptIn::fall(function<void()> _func){
    fallfunc = _func;
}
