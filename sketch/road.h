#pragma once

#include "HardwareSerial.h"
#include "Arduino.h"
#include "trafficLight.h"

class road : public trafficLight {
private:
  int count = 0;
  int Sensor;

public:
  road(int S0, int S1, int Sensor);
  // void setup(int S0, int S1, int Sensor);
  void senseCar();
  void loop();
  int getCount() {
    return count;
  }
};

road::road(int S0, int S1, int Sensor) : trafficLight(S0, S1){
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
  if (isRed() == true)
    senseCar();
}
