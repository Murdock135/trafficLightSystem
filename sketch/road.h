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
  int calcDensity();
  int greenTime();
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

int road::calcDensity(){
  //1,2 and 3 indicate levels of traffic density from 1=low to 3=high
  if((count<=3)&(count>0))
    return 1;
  else if((count>3)&&(count<7))
    return 2;
  else if(count>=7)
    return 3;
  else if(count==0)
    return 0;
}

int road::greenTime(){
  //no greentime for calcDensity==0
  if(calcDensity()==1)
    return 3000;
  if(calcDensity()==2)
    return 6000;
  if(calcDensity()==3)
    return 8000;
}