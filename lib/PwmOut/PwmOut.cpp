#include "PwmOut.hpp"

PwmOut::PwmOut(PinName _pin, uint8_t _ch): pin(_pin), ch(_ch)
{
    bool pin_match = false;
    switch (_pin)
    {
        case 0: pin_match = true; break;
        case 2: pin_match = true; break;
        case 4: pin_match = true; break;
        case 12: pin_match = true; break;
        case 13: pin_match = true; break;
        case 14: pin_match = true; break;
        case 15: pin_match = true; break;
        case 25: pin_match = true; break;
        case 26: pin_match = true; break;
        case 27: pin_match = true; break;
        case 32: pin_match = true; break;
        case 33: pin_match = true; break;

        default:
            break;
    }

    if(pin_match)
    {
        Serial.println("pinMode");
        pinMode(pin, OUTPUT);
        
        ledcSetup(ch, freq, resolution_bits);
        ledcAttachPin(pin, ch);
        ledcWrite(ch, 0);
        
    } else {
        printf("wrong assignment of pwm pin");
        delete this;
    }
}

void PwmOut::operator=(float _duty){
    write(_duty);
}

void PwmOut::write(float _duty){
    duty = _duty;
    ledcWrite(ch, (int)(_duty * 1024));
}

void PwmOut::period(float _period){
    period_us((unsigned int)(1 / _period) * 1000000);
}

void PwmOut::period_ms(unsigned int _period_ms){
    period_us((unsigned int)(1000 / _period_ms) * 1000);
}

void PwmOut::period_us(unsigned int _period_us){
    freq = (int)(pow(10, 6) / _period_us);
    ledcChangeFrequency(ch, freq, resolution_bits);
}

void PwmOut::suspend(){
    ledcWrite(ch, 0);
}

void PwmOut::resume(){
    ledcWrite(ch, duty);
}