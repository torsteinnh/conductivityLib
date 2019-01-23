/*
Implementation of library for conductivitySensor
*/

#include <Arduino.h>
#include "conductivitySensor.h"

#pragma once

conductivitySensor::conductivitySensor(int digital1, int digital2, int analog1, int delayMs = 5, int cycles = 4){
  this->_dp1 = digital1;
  this->_dp2 = digital2;
  this->_ap = analog1;
  this->delay = delayMs;
  this->cycles = cycles

  pinMode(_dp1, OUTPUT);
  pinMode(_dp2, OUTPUT);
  digitalWrite(_dp1, LOW);
  digitalWrite(_dp2, LOW);
}

int conductivitySensor::getValue(){ return reading; }

void conductivitySensor::measure(){
  for(i = 0; i < this->cycles; i++){
    pinMode(_dp1, HIGH);
    pinMode(_dp2, LWO);
    delay(this->delay);

    this->reading += analogRead(_ap);

    pinMode(_d1, LOW);
    pinMode(_d2, HIGH);
    delay(this->delay);
  }
  this->reading = this->reading / this->cycles;
}
