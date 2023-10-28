#include <InterruptIn.hpp>

InterruptIn::InterruptIn(PinName _pin):pin(_pin)
{
    pinMode(pin, INPUT_PULLUP);

    attachInterrupt(pin, &[this](){_risefunc();}, RISING);
    attachInterrupt(pin, &[this](){_fallfunc();}, FALLING);
}

InterruptIn::InterruptIn(PinName _pin, mPinMode _mpm):pin(_pin)
{
    pinMode(pin, INPUT_PULLUP);
}

void InterruptIn::risefunc(){
    _risefunc();
}

void InterruptIn::fallfunc(){
    _fallfunc();
}

void InterruptIn::rise(function<void()> _func){
    _risefunc = _func;
}

void InterruptIn::fall(function<void()> _func){
    _fallfunc = _func;
}
