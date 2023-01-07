#include "road.h"
#include "trafficLight.h"
#include "controller.h"
#include "InfraRed.h"

road r1("r1", 7, 13, 12);
road r2("r2", 6, 11, 10);
infraRed i(7);
trafficLight tl1(13,12);
controller c;

void setup() {
  Serial.begin(1200);
  // r1.setup();
  // r2.setup();
  // i.setup();
  c.setup();
}
int s = 1;
void loop() {
  // r1.turnRed();
  // r2.turnRed();
  // delay(1000);
  // r1.turnGreen();
  // r2.turnGreen();
  // delay(1000);
  tl.turnRed();
  delay(1000);
  tl.turnGreen();
  
}