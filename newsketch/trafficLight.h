#include "HardwareSerial.h"
#include "pins_arduino.h"
#include "Arduino.h"
#pragma once

class trafficLight {
private:
  int inputPinRed;
  int inputPinGreen;
public:
  trafficLight(int inputPinRed, int inputPinGreen)
    : inputPinRed(inputPinRed), inputPinGreen(inputPinGreen) {}
  void setup() {
    Serial.begin(1200);
    pinMode(inputPinRed, OUTPUT);
    pinMode(inputPinGreen, OUTPUT);
  }
  void turnRed() {
    digitalWrite(inputPinRed, HIGH);
    digitalWrite(inputPinGreen, LOW);
  }
  void turnGreen() {
    digitalWrite(inputPinRed, LOW);
    digitalWrite(inputPinGreen, HIGH);
  }
  bool isRed() {
    bool red;
    if (digitalRead(inputPinRed) == HIGH) {
      red = true;
      Serial.println("Red");
    } else {
      red = false;
      Serial.println("Green");
    }
    return red;
  }
};