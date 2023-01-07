#include "road.h"
#include "trafficLight.h"
#include "controller.h"
using namespace std;

road r1("r1", 1, 2, 9);
road r2("r2", 3, 4, 10);
road r3("r3", 5, 6, 11);
road r4("r4", 7, 8, 12);

void setup() {
  Serial.begin(1200);
  r1.setup();
  r2.setup();
  r3.setup();
  r4.setup();
}


int i = 1;
void loop() {
  Serial.println(i);
  // r2.printPins();

  // r1.yellow();
  // r2.yellow();
  // r3.yellow();
  // r4.yellow();
  // r1.greenStraight();
  // r2.greenStraight();
  // r3.greenStraight();
  // r4.greenStraight();


  controller c(r1, r2, r3, r4);

  c.setup();

  // long int programStart = millis();
  // long int Duration = 0;
  // if (i == 1) {
  //   r1.red();
  //   r2.red();
  //   r3.red();
  //   r4.red();

  //   while (Duration <= 2000) {
  //     Duration = millis() - programStart;
  //     r1.loop();
  //     r2.loop();
  //     r3.loop();
  //     r4.loop();
  //   }
  // }
  // i = 2;
  c.loop();
}
