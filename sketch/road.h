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
  void setup();
  void senseCar();
  void loop();
  int getCount() {
    //Count works
    return count;
  }
};

road::road(String name, int S0, int S1, int Sensor)
  : trafficLight(S0, S1), name(name), Sensor(Sensor) {}

void road::setup() {
  Serial.begin(1200);
  trafficLight::setup();   //setup traffic light
  pinMode(Sensor, INPUT);  //setup sensors
  Serial.println( Sensor);
}

void road::senseCar() {
  if (digitalRead(Sensor) == LOW) {
    Serial.println(digitalRead(Sensor));
    ++count;
  }
}

void road::loop() {
  Serial.println(name+ ":");
  if (isRed() == true) {
    senseCar();
  } else {
    count = 0;
    Serial.println("-");
  }
}
