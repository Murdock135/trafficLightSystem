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


  int trafficDensity(int carCount) {
    int density;
    if (carCount < 5)
      density = 1;
    else if ((carCount > 4 && (carCount < 8)))
      density = 2;
    else
      density = 3;
    return density;
  }
  int greenDuration(int trafficDensity) {
    if (trafficDensity == 1)
      return 2000;
    else if (trafficDensity == 2)
      return 5000;
    else
      return 7000;
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
    int dr1 = trafficDensity(r1.getCount());
    int dr2 = trafficDensity(r2.getCount());
    int dr3 = trafficDensity(r3.getCount());
    int dr4 = trafficDensity(r4.getCount());
    int greenTime = greenDuration(dr1);
    int drs[] = { dr1, dr2, dr3, dr4 };
    int drSize = 4;
    int* drPtrs[4];
    drPtrs[0] = &dr1;
    drPtrs[1] = &dr2;
    drPtrs[2] = &dr3;
    drPtrs[3] = &dr4;
    int largestdr = largestElement(drs, 4);

    if (*drPtrs[0] == largestdr) {
      r1.turnGreen();
      greenTime = greenDuration(dr1);
      runProgramForDuration(greenTime, r1, r2, r3, r4);
      Serial.println("r1 given green");
      r2.turnRed();
      r3.turnRed();
      r4.turnRed();
    } else if (*drPtrs[1] == largestdr) {
      r2.turnGreen();
      greenTime = greenDuration(dr2);
      runProgramForDuration(greenTime, r1, r2, r3, r4);
      Serial.println("r2 given green");
      r1.turnRed();
      r3.turnRed();
      r4.turnRed();
    } else if (*drPtrs[2] == largestdr) {
      r3.turnGreen();
      greenTime = greenDuration(dr3);
      runProgramForDuration(greenTime, r1, r2, r3, r4);
      r1.turnRed();
      r2.turnRed();
      r4.turnRed();
    } else {
      r4.turnGreen();
      greenTime = greenDuration(dr4);
      runProgramForDuration(greenTime, r1, r2, r3, r4);
      r1.turnRed();
      r2.turnRed();
      r3.turnRed();
    }
  }

  int largestElement(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
      if (max < arr[i]) {
        max = arr[i];
      }
    }
    return max;
  }
};