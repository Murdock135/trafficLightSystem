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


  int trafficDensity(int pairTotal) {
    int density;
    if (pairTotal < 5)
      density = 1;
    else
      density = 2;
    return density;
  }
  int greenDuration(int trafficDensity) {
    if (trafficDensity == 1)
      return 2000;
    else
      return 5000;
  }
  void runProgramForDuration(int d, road& r1, road& r2, road& r3, road& r4) {
    int startTime = millis();
    int duration = 0;
    while (duration < d) {
      duration = millis() - startTime;
      r1.Sense();
      r2.Sense();
      r3.Sense();
      r4.Sense();
    }
  }
  void control_algo(road& r1, road& r2, road& r3, road& r4) {
    Serial.println("algo initiating");
    int x = r1.getCount() + r3.getCount();
    int y = r2.getCount() + r4.getCount();
    int dx = trafficDensity(x);
    int dy = trafficDensity(y);
    Serial.println(dx);
    Serial.println(dy);
    int greenTime = greenDuration(dx);

    if (dx > dy) {
      r1.turnGreen();
      r3.turnGreen();
      greenTime = greenDuration(dx);
      Serial.println("r1 and r3 given green");
    } else if (dx < dy) {
      r2.turnGreen();
      r4.turnGreen();
      greenTime = greenDuration(dy);
      Serial.println("r2 and r4 given green");
    } else {
      Serial.println("Both are equal, r1 and r3 given green");
      r1.turnGreen();
      r3.turnGreen();
      greenTime = greenDuration(dx);
    }
    runProgramForDuration(greenTime, r1, r2, r3, r4);
  }
};