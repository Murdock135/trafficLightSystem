#pragma once

#include "HardwareSerial.h"
#include "Arduino.h"
#include "trafficLight.h"

class road : public trafficLight {
private:
  int count = 0;
  int Sensor = 0;
public:
  String name;
  road(String name, int S0, int S1, int Sensor);
  // void setup(int S0, int S1, int Sensor);
  void senseCar();
  void loop();
  int getCount() {
    return count;
  }
  int calcDensity();
  int greenTime();
};

road::road(String name, int S0, int S1, int Sensor) : trafficLight(S0, S1), name(name){
  setup(); //setup traffic light
  pinMode(Sensor, INPUT);  //setup sensors
}

void road::senseCar() {
  if (digitalRead(Sensor) == LOW) {
    Serial.println(count);
    ++count;
  }
}

void road::loop() {
  if (isRed() == true) {
    Serial.println(name + ":" + "00");
    senseCar();
  }
  else{
    Serial.print("...");
  }
}

