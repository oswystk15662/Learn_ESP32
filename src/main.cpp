#include <Arduino.h>
#include "PwmOut.hpp"

void u_main();

void setup() {
  u_main();
}

void loop() {
}
/*********************/

PwmOut pwm(2, 0);

void u_main(){
  pwm = 0.5;
}