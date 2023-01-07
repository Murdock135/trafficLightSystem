#include "HardwareSerial.h"
#include "pins_arduino.h"
#include "Arduino.h"
#pragma once

class trafficLight {
private:
  int s0pin;
  int s1pin;
public:
  trafficLight(int s0, int s1)
    : s0pin(s0), s1pin(s1) {}

  void setup() {
    Serial.begin(1200);
    pinMode(s0pin, OUTPUT);
    pinMode(s1pin, OUTPUT);
  }
  void turnRed() {
    digitalWrite(s0pin, LOW);
    digitalWrite(s1pin, LOW);
  }
  void turnGreen() {
    digitalWrite(s0pin, HIGH);
    digitalWrite(s1pin, LOW);
  }
  void turnYellow() {
    digitalWrite(s0pin, LOW);
    digitalWrite(s1pin, HIGH);
  }

  void turnGreenTime(int time) {
    int startTime = millis();
    int duration = 0;
    while (duration < time) {
      duration = millis() - startTime;
      turnGreen();
    }
  }

  bool isRed() {
    bool red;
    if ((digitalRead(s0pin) == LOW) && (digitalRead(s1pin) == LOW)) {
      red = true;
    } else {
      red = false;
    }
    return red;
  }
  bool isGreen() {
    bool green;
    if ((digitalRead(s0pin) == HIGH) && (digitalRead(s1pin) == LOW)) {
      green = true;
    } else {
      green = false;
    }
    return green;
  }
};