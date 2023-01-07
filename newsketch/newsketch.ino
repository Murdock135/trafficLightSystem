#include "road.h"
#include "trafficLight.h"
#include "controller.h"
#include "InfraRed.h"

road r1("r1", 7, 13, 12);
road r2("r2", 6, 11, 10);
road r3("r3", 5, 8, 9);
infraRed i(7);
trafficLight tl1(13, 12);
controller c;

void setup() {
  Serial.begin(1200);
  r1.setup();
  r2.setup();
  r3.setup();
  i.setup();
  c.setup();
  tl1.setup();
}
int s = 1;
void loop() {
  Serial.println("program loop start");
  // Serial.print("s = ");
  // Serial.println(s);
  // r1.turnGreen();
  // r1.Sense();
  // Serial.println(r1.getCount());
  // r2.turnRed();
  // delay(1000);
  // r1.turnGreen();
  // r2.turnGreen();
  // delay(1000);
  // Serial.println(i.output());
  // r1.turnGreen();
  // Serial.println(r1.getCount());
  // Serial.println(r2.getCount());
  // r1.Sense();
  // r1.increaseCarCount();
  int startTime = millis();
  int duration = 0;
  // // if (s == 1) {
  r1.turnRed();
  r2.turnRed();
  r3.turnRed();

  while (duration < 10000) {
    duration = millis() - startTime;
    r1.Sense();
    r2.Sense();
    r3.Sense();
  }
  Serial.println(r1.getCount());
  Serial.println(r2.getCount());
  Serial.println(r3.getCount());
  //   s = 2;
  // }
  c.control_algo_between3roads(r1, r2, r3);
}