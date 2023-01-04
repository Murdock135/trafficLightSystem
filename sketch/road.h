#pragma once

#include "trafficLight.h"

class road {
private:
  trafficLight tl;
public:
  int carCount = 0;
  int sensorPin;
  void setupTL(int pin);
  void senseCar();
  void loop();
};

void road::senseCar(){
  if(digitalRead(sensorPin)==LOW)
    ++carCount;
}

void road::setupTL(int pin){
  trafficLight newTL(pin);
  tl = newTL;
}

void road::loop(){
  senseCar();

}