#include "Arduino.h"
#include "pins_arduino.h"
#include "HardwareSerial.h"
#include "WString.h"
#pragma once
#include "trafficLight.h"
#include "InfraRed.h"


class road : public infraRed, public trafficLight {
private:
  String name;
  int count = 0;
public:
  road(String name, int infraRedpin, int trafficLightRedpin, int trafficLightGreenpin)
    : infraRed(infraRedpin), trafficLight(trafficLightRedpin, trafficLightGreenpin), name(name) {}
  void setup() {
    Serial.begin(1200);
    trafficLight::setup();
    infraRed::setup();
  }
  int getCount() {
    return count;
  }
  void setCount(int x) {
    count = x;
  }
  void increaseCarCount() {
    ++count;
  }
};