#include <Arduino.h>
#include "PwmOut.hpp"

void u_main(){
  Serial.begin(9600);

  Serial.println("start");

  PwmOut pwm(15, 0);
  //pwm.period_ms(500);
  for(float f = 0.0f; f < 1.0f; f += 0.05f){
    pwm = f;
    delay(1000);
  }

  while(1){
    /*digitalWrite(15, HIGH);
    delay(500);
    digitalWrite(15, LOW);
    delay(500);*/
  }
}

void setup() { u_main(); }
void loop() {}