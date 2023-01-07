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
};