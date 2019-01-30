/*
Implementation of library for conductivitySensor
*/

#include <Arduino.h>
#include "conductivityLib.h"

#pragma once

conductivitySensor::conductivitySensor(int digital1, int digital2, int analog1, int pauseMs = 1, int cycles = 4){
  this->_dp1 = digital1;
  this->_dp2 = digital2;
  this->_ap = analog1;
  this->pause = pauseMs;
  this->cycles = cycles;

  pinMode(digital1, OUTPUT);
  pinMode(digital2, OUTPUT);
  digitalWrite(digital1, LOW);
  digitalWrite(digital2, LOW);
}

int conductivitySensor::getValue(){ return reading; }


void conductivitySensor::measure(){
  this->reading = 0;
  
  for(int i = 0; i < this->cycles; i++){
    digitalWrite(this->_dp1, HIGH);
    digitalWrite(this->_dp2, LOW);
    delay(this->pause);

    this->reading += analogRead(_ap);

    digitalWrite(this->_dp1, LOW);
    digitalWrite(this->_dp2, HIGH);
    delay(this->pause);

    this->reading += 1023 - analogRead(_ap);
  }
  this->reading = this->reading / (2*this->cycles);
  noCurrent();
}


void conductivitySensor::noCurrent(){
  digitalWrite(this->_dp1, LOW);
  digitalWrtie(this->_dp2, LOW);
}
