#include "Arduino.h"
#include "HardwareSerial.h"
#pragma once
#include "road.h"
#include "trafficLight.h"
#include "InfraRed.h"

class controller {
private:
public:
  void setup() {
    Serial.begin(1200);
  }
  void increaseCarCount(road& r) {
    r.increaseCarCount();
  }


  int trafficDensityTwoRoads(road& r1, road& r2) {
    int density;
    int total = r1.getCount() + r2.getCount();
    if (total < 10)
      density = 1;
    else
      density = 2;
    return density;
  }
  int greenDuration(int trafficDensity) {
    if (trafficDensity == 1)
      return 2000;
    else
      return 4000;
  }
  void runProgramForDuration(int d, road& r1, road& r2, road& r3) {
    int startTime = millis();
    int duration = 0;
    while (duration < d) {
      duration = millis() - startTime;
      r1.Sense();
      r2.Sense();
      r3.Sense();
    }
  }
  void control_algo_between3roads(road& r1, road& r2, road& r3) {
    //assuming road1 and road3 are a pair of opposing roads
    Serial.println("algo initiating");
    int x = r1.getCount() + r3.getCount();
    int y = r2.getCount();
    Serial.println(x);
    Serial.println(y);
    if (x > y) {
      r1.turnGreen();
      r3.turnGreen();
      Serial.println("r1 and r3 given green");
    } else if (x < y) {
      r2.turnGreen();
      Serial.println("r2 given green");
    } else {
      Serial.println("Both are equal, r1 and r3 given green");
      r1.turnGreen();
      r3.turnGreen();
    }
    runProgramForDuration(3000, r1, r2, r3);
  }
};