#include "road.h"
#include "trafficLight.h"
#include "controller.h"
#include "InfraRed.h"

road r1("r1", 10, 2, 3);
road r2("r2", 11, 4, 5);
road r3("r3", 12, 6, 7);
road r4("r4", 13, 8, 9);
controller c;

void setup() {
  Serial.begin(1200);
  r1.setup();
  r2.setup();
  r3.setup();
  r4.setup();
  c.setup();
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
  r4.turnRed();

  while (duration < 10000) {
    duration = millis() - startTime;
    r1.Sense();
    r2.Sense();
    r3.Sense();
    r4.Sense();
  }
  Serial.println(r1.getCount());
  Serial.println(r2.getCount());
  Serial.println(r3.getCount());
  Serial.println(r4.getCount());
  //   s = 2;
  // }
  c.control_algo(r1, r2, r3, r4);
}