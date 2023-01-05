#pragma once
#include "Arduino.h"
#include "pins_arduino.h"


class trafficLight {
protected:
  int S0;
  int S1;
public:
  trafficLight(int tempS0, int tempS1) : S0(tempS0), S1(tempS1) {}
  trafficLight();
  void setup(){
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
  }
  void red() {
    digitalWrite(S0, HIGH);
    digitalWrite(S1, HIGH);
  }
  void yellow() {
    digitalWrite(S0, LOW);
    digitalWrite(S1, HIGH);
  }
  void greenStraight(){
    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);
  }
  void greenStraightAndRight(){
    digitalWrite(S0, HIGH);
    digitalWrite(S1, HIGH);
  }
  bool isRed(){
    bool redStatus = false;
    if((digitalRead(S0)==LOW)&&(digitalRead(S1)==LOW))
      redStatus = true;
    return redStatus;
  }
  void setS0pin(int S0) {
    this->S0 = S0;
  }
  void setS1pin(int S1) {
    this->S1 = S1;
  }
  
};
