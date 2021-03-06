/*
Written by torsteinnh


Library for resistance-measuring sensors prone to electrolysis
where the reaction is reversible and non-nangerous.


The intended workflow is with a diagram as follows:
(a pdf of the same figure is available in the extras folder)
    -------------+
		 |
	       D1+------+
		 |	|
     Arduino   	 |	Sensor
	       A1+------+
		 |     +++
	         |     | |  <-Properly sized resistor
	         |     +++
	       D2+------+
	         |
    -------------+
Make a "conductivitySensor" object initialized with two digital
pins and one analog, the pinmodes will be set by the libraries.
The sensor sould be two cables with a measured resistance
between, for instance 1 cm of whet soil or some riverwater.
*/

#include <Arduino.h>

#pragma once

class conductivitySensor{
public:
  conductivitySensor(int digital1, int digital2, int analog1, int R, int pauseMs = 1, int cycles = 4, double Vcc = 5, int sMax = 1024);
  int getValue();
  void measure();
  void noCurrent();
  int resistance();
private:
  int _dp1;
  int _dp2;
  int _ap;
  int pause;
  int cycles;
  int reading;
  int resistor;
  double Vcc;
  int sMax;
};
