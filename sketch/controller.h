#pragma once
#include "road.h"

class controller {
public:
  int calcDensity(road r1, road r2) {
    //r1 and r2 are a pair of roads
    //1,2 and 3 indicate levels of traffic density from 1=low to 3=high
    int r1count = r1.getCount();
    int r2count = r2.getCount();
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
  long int greenTime(int trafficDensity) {
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
  void keepLightOn(road r, long int requiredDuration, int lightColor) {
    //lightColor: 00 is red, 10 is yellow, 01 is green and 11 is green and straight
    switch (lightColor) {
      case 00:
        r.red();
      case 10:
        r.yellow();
      case 01:
        r.greenStraight();
      case 11:
        r.greenStraightAndRight();
    }
    long int lightStartTime = millis();
    long int duration = 0;
    while (duration < requiredDuration) {
      duration = millis() - lightStartTime;
    }
    if(lightColor==10) //if color was yellow, turn red after duration has passed
      r.red();
  }
  void controlAlgorithm(road r1, road r2, road r3, road r4) {
    int r1r3_density = calcDensity(r1, r3);
    int r2r4_density = calcDensity(r2, r4);

    if (((r1r3_density == r2r4_density) && (r1r3_density != 0)) || (r1r3_density > r2r4_density)) {
      long int greenDuration = this->greenTime(r1r3_density);
      this->keepLightOn(r1, greenDuration, 'g');
      this->keepLightOn(r3, greenDuration, 'g');
      this->keepLightOn(r1, 1000, 'y');
      this->keepLightOn(r3, 1000, 'y');
    }

    else if (r1r3_density < r2r4_density) {
      //make two and four green (only straight)
      long int greenDuration = this->greenTime(r2r4_density);
      this->keepLightOn(r2, greenDuration, 'g');
      this->keepLightOn(r4, greenDuration, 'g');
      this->keepLightOn(r2, 1000, 'y');
      this->keepLightOn(r4, 1000, 'y');
    } else if ((r1.getCount() == 0) && (r2.getCount() == 0) && (r3.getCount() == 0) && (r4.getCount() == 0)) {
      r1.greenStraight();  //keep road one green if every road is empty
    }
  }
};