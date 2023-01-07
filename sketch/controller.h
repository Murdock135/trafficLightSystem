#include "HardwareSerial.h"
#pragma once
#include "road.h"

class controller {
private:
  road r1, r2, r3, r4;
public:
  controller(road r1, road r2, road r3, road r4)
    : r1(r1), r2(r2), r3(r3), r4(r4) {}
  int calcDensity(road, road);
  unsigned long int greenTime(int);
  void keepLightOn(String, unsigned long int, int);
  void controlAlgorithm();
  void setup();
  void loop();
};
void controller::setup() {
  Serial.begin(1200);
}

void controller::loop() {
  controlAlgorithm();
}

int controller::calcDensity(road firstRoad, road secondRoad) {
  //r1 and r2 are a pair of roads
  //1,2 and 3 indicate levels of traffic density from 1=low to 3=high

  int r1count = firstRoad.getCount();
  int r2count = secondRoad.getCount();

  int total = r1count + r2count;
  if ((total <= 3) & (total > 0))
    return 1;
  else if ((total > 3) && (total < 7))
    return 2;
  else if (total >= 7)
    return 3;
  else
    return 0;
}

unsigned long int controller::greenTime(int trafficDensity) {
  //no greentime for calcDensity==0
  if (trafficDensity == 1)
    return 3000;
  if (trafficDensity == 2)
    return 6000;
  if (trafficDensity == 3)
    return 8000;
  else
    return 0;
}

void controller::keepLightOn(String road, unsigned long int requiredDuration, int lightColor) {
  //lightColor: 00 is red, 10 is yellow, 01 is green and 11 is green and straight
  r1.red();
  r2.red();
  r3.red();
  r4.red();
  if ((road == "r1") || (road == "r3")) {
    switch (lightColor) {
      case 00:
        r1.red();
        r3.red();
        break;
      case 01:
        r1.yellow();
        r3.yellow();
        break;
      case 10:
        r1.greenStraight();
        r3.greenStraight();
        break;
      case 11:
        r1.greenStraightAndRight();
        r3.greenStraightAndRight();
        break;
    }
    unsigned long int lightStartTime = millis();
    unsigned long int duration = 0;
    while (duration < requiredDuration) {
      duration = millis() - lightStartTime;
      r2.loop();
      r4.loop();
    }
  } else if ((road == "r2") || (road == "r4")) {
    switch (lightColor) {
      case 00:
        r2.red();
        r4.red();
        break;
      case 01:
        r2.yellow();
        r4.yellow();
        break;
      case 10:
        r2.greenStraight();
        r4.greenStraight();
        break;
      case 11:
        r2.greenStraightAndRight();
        r4.greenStraightAndRight();
        break;
    }
    unsigned long int lightStartTime = millis();
    unsigned long int duration = 0;
    while (duration < requiredDuration) {
      duration = millis() - lightStartTime;
      r1.loop();
      r3.loop();
    }

    if (lightColor == 01) {
      r1.red();
      r3.red();
    }
  }
}

void controller::controlAlgorithm() {
  int r1r3_density = calcDensity(r1, r3);
  int r2r4_density = calcDensity(r2, r4);
  Serial.println(r1r3_density);
  Serial.println(r2r4_density);
  if (((r1r3_density == r2r4_density) && (r1r3_density != 0)) || (r1r3_density > r2r4_density)) {
    unsigned long int greenDuration = greenTime(r1r3_density);
    keepLightOn("r1", greenDuration, 10);
    keepLightOn("r1", 1000, 01);
    r1.red();
    r3.red();
  }

  else if (r1r3_density < r2r4_density) {
    unsigned long int greenDuration = greenTime(r2r4_density);
    keepLightOn("r2", greenDuration, 10);
    keepLightOn("r2", 1000, 01);
    r2.red();
    r4.red();
  } else if ((r1.getCount() == 0) && (r2.getCount() == 0) && (r3.getCount() == 0) && (r4.getCount() == 0)) {
    keepLightOn("r1", 5000, 10);
  }
}
