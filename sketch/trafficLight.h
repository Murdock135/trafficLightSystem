#pragma once
#include "Arduino.h"
#include "pins_arduino.h"


class trafficLight {
public:
  int S0;
  int S1;
  trafficLight(int tempS0, int tempS1) : S0(tempS0), S1(tempS1) {}
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

};
