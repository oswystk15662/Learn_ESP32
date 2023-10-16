#pragma once

#include <Arduino.h>

using namespace std;

typedef uint8_t PinName;
typedef uint8_t mPinMode;

class InterruptIn{
private:
    PinName pin;
    function<void(void)> _risefunc;
    function<void(void)> _fallfunc;

    void risefunc();
    void fallfunc();

public:
    InterruptIn(PinName _pin);
    InterruptIn(PinName _pin, mPinMode _mode); // mbed has their defs of pinmode, but i mendo preparing it.

    void rise(function<void(void)> _func);
    void fall(function<void(void)> _func);
};
