#include "HardwareSerial.h"
#pragma once
#include "Arduino.h"
#include "pins_arduino.h"


class trafficLight {
protected:
  int S0;
  int S1;
public:
  trafficLight(int S0, int S1)
    : S0(S0), S1(S1) {}
  trafficLight();
  void setup() {
    Serial.begin(1200);
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
  }
  void red() {
    digitalWrite(S0, LOW);
    digitalWrite(S1, LOW);
  }
  void yellow() {
    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);
  }
  void greenStraight() {
    digitalWrite(S0, LOW);
    digitalWrite(S1, HIGH);
  }
  void greenStraightAndRight() {
    digitalWrite(S0, HIGH);
    digitalWrite(S1, HIGH);
  }
  bool isRed() {
    bool redStatus = false;
    if ((digitalRead(S0) == LOW) && (digitalRead(S1) == LOW))
      redStatus = true;
    return redStatus;
  }
  void printPins(){
    Serial.print("Pins are ");
    Serial.print(S0);
    Serial.print(" and ");
    Serial.print(S1);
    Serial.println("");
  }
};
