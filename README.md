# conductivityLib

## Overview

Many resistancemeasuring sensors such as moisture and conductivitysensors work by applying
a voltage between two electrodes.
If the voltage applied is static DC it may corrode the electrodes fast destroying the sensor.

This library is a simple tool to decrease the time in which current runs through the sensor
and apply an AC current to reverse some of the damage.


## Usage

### API

The library contains one class:

conductivitySensor

It has the following methods:

int getValue();
Returns the last read value from the sensor.

void measure();
Runs a measurement on the sensor, this measures the value returned by getValue.

void noCurrent();
Stops all current through the sensor.


### Expected hardware

Schematics of sugested usage:

![image](extras/circuit.pdf)
