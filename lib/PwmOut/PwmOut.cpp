#include "PwmOut.hpp"

PwmOut::PwmOut(PinName _pin, uint8_t _ch): pin(_pin), ch(_ch)
{
    Serial.begin(115200);
    if( _pin != 0 ||
        _pin != 2 ||
        _pin != 4 ||
        _pin != 12 ||
        _pin != 13 ||
        _pin != 14 ||
        _pin != 15 ||
        _pin != 25 ||
        _pin != 26 ||
        _pin != 27 ||
        _pin != 32 ||
        _pin != 33
        )
    {
        Serial.println("wrong assignment of pwm pin");
        delete this;
    }
    else{
        ledcSetup(this->ch, this->freq, this->resolution_bits);
        ledcAttachPin(this->pin, this->ch);
    }
}

void PwmOut::operator=(float _duty){
    this->write(_duty);
}

void PwmOut::write(float _duty){
    this->duty = _duty;
    ledcWrite(this->ch, (int)(_duty * 1024));
}

void PwmOut::period(float _period){
    this->period_us((unsigned int)(1 / _period) * 1000000);
}

void PwmOut::period_ms(unsigned int _period_ms){
    this->period_us((unsigned int)(1000 / _period_ms) * 1000);
}

void PwmOut::period_us(unsigned int _period_us){
    this->freq = (int)(pow(10, 6) / _period_us);
    ledcChangeFrequency(this->ch, this->freq, this->resolution_bits);
}

void PwmOut::suspend(){
    ledcWrite(this->ch, 0);
}

void PwmOut::resume(){
    ledcWrite(this->ch, this->duty);
}