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
void loop() {

  r1.turnRed();
  r2.turnRed();
  r3.turnRed();
  r4.turnRed();

  c.control_algo(r1, r2, r3, r4);
}