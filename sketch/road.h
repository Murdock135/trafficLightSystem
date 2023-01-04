#pragma once
#include "Arduino.h"
#include "trafficLight.h"

class road : public trafficLight {
private:
  trafficLight tl;
public:
  int lCount = 0;
  int rCount = 0;
  int leftSensor;
  int rightSensor;
  road();
  void setup(int S0, int S1, int leftSensor, int rightSensor);
  void senseCarLeft();
  void senseCarRight();
  void loop();
};

void road::setup(int S0, int S1, int leftSensor, int rightSensor){
  //setup demux pins for traffic light
  tl.S0 = S0;
  tl.S1 = S1;
  tl.setup();
  //setup sensors
  pinMode(leftSensor, OUTPUT);
  pinMode(rightSensor, OUTPUT);
}

void road::senseCarLeft(){
  if(digitalRead(leftSensor)==LOW);
    ++lCount;
}

void road::senseCarRight(){
  if(digitalRead(rightSensor)==LOW);
    ++rCount;
}

void road::loop(){
  senseCarLeft();
  senseCarRight();
}
