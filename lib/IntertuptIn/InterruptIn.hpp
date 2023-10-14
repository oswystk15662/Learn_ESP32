#pragma once

#include <Arduino.h>
#include "uniques.hpp"

class InterruptIn{
private:
    PinName pin;
    risefunc = []{return;}
    fallfunc = []{return;}

public:
    InterruptIn(PinName _pin);
    InterruptIn(PinName _pin, mPinMode _mode);// mbed has their defs of pinmode, but i mendo preparing it.

    void rise(function<void()> _func);
    void fall(function<void()> _func);
};
