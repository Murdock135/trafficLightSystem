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
  road(String name, int infraRedpin, int s0demux, int s1demux)
    : infraRed(infraRedpin), trafficLight(s0demux, s1demux), name(name) {}
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
  void Sense() {
    if (isRed() == true) {
      Serial.println("red");
      if (output() == 0) {
        Serial.print(name);
        Serial.println("Detected");
        count = count + 1;
      }
    } else if (isGreen() == true) {
      Serial.println("green");
      setCount(0);
      count = 0;
    } else {
      Serial.println("not green or red");
    }
  }
};