#pragma once
#include "road.h"

class controller {
private:
  road r1, r2, r3, r4;
public:
  controller(road r1, road r2, road r3, road r4)
    : r1(r1), r2(r2), r3(r3), r4(r4) {}
  int calcDensity(road, road);
  long int greenTime(int);
  void keepLightOn(String, long int, int);
  void controlAlgorithm();
};

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
long int controller::greenTime(int trafficDensity) {
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
void controller::keepLightOn(String road, long int requiredDuration, int lightColor) {
  //lightColor: 00 is red, 10 is yellow, 01 is green and 11 is green and straight
  if ((road == "r1") || (road == "r3")) {
    switch (lightColor) {
      case 00:
        r1.red();
        r3.red();
      case 10:
        r1.yellow();
        r3.yellow();
      case 01:
        r1.greenStraight();
        r3.greenStraight();
      case 11:
        r1.greenStraightAndRight();
        r3.greenStraightAndRight();
    }


    long int lightStartTime = millis();
    long int duration = 0;
    while (duration < requiredDuration) {
      duration = millis() - lightStartTime;
      r2.loop();
      r4.loop();
    }
    if (lightColor == 10)  //if color was yellow, turn red after duration has passed
      r1.red();
    r3.red();
  } else if ((road == "r2") || (road == "r4")) {
    switch (lightColor) {
      case 00:
        r2.red();
        r4.red();
      case 10:
        r2.yellow();
        r4.yellow();
      case 01:
        r2.greenStraight();
        r4.greenStraight();
      case 11:
        r2.greenStraightAndRight();
        r4.greenStraightAndRight();
    }


    long int lightStartTime = millis();
    long int duration = 0;
    while (duration < requiredDuration) {
      duration = millis() - lightStartTime;
      r1.loop();
      r3.loop();
    }
    if (lightColor == 10)  //if color was yellow, turn red after duration has passed
      r2.red();
    r4.red();
  }
}
void controller::controlAlgorithm() {
  int r1r3_density = calcDensity(r1, r3);
  int r2r4_density = calcDensity(r2, r4);

  if (((r1r3_density == r2r4_density) && (r1r3_density != 0)) || (r1r3_density > r2r4_density)) {
    r2.loop();
    r4.loop();
    long int greenDuration = this->greenTime(r1r3_density);
    this->keepLightOn("r1", greenDuration, 01);
    this->keepLightOn("r3", greenDuration, 01);
    this->keepLightOn("r1", 1000, 10);
    this->keepLightOn("r3", 1000, 10);
  }

  else if (r1r3_density < r2r4_density) {
    r1.loop();
    r3.loop();
    long int greenDuration = this->greenTime(r2r4_density);
    this->keepLightOn("r2", greenDuration, 01);
    this->keepLightOn("r4", greenDuration, 01);
    this->keepLightOn("r2", 1000, 10);
    this->keepLightOn("r4", 1000, 10);
  } else if ((r1.getCount() == 0) && (r2.getCount() == 0) && (r3.getCount() == 0) && (r4.getCount() == 0)) {
    r1.greenStraight();  //keep road one green if every road is empty
  }
}
