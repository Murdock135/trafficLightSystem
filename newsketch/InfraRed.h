#include "HardwareSerial.h"
#include "Arduino.h"
#pragma once

class infraRed {
private:
  int inputPin;
public:
  infraRed(int inputPin)
    : inputPin(inputPin) {}
  void setup() {
    Serial.begin(1200);
    pinMode(inputPin, INPUT);
  }
  int output() {
    return digitalRead(inputPin);
  }
};