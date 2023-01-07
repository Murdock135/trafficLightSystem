#include "road.h"
#include "trafficLight.h"
#include "controller.h"
#include "InfraRed.h"

road r1("r1", 10, 2, 3);
road r2("r2", 11, 4, 5);
road r3("r3", 12, 6, 7);
road r4("r4", 13, 8, 9);
infraRed i(10);
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

  // Serial.println("program loop start");
  // Serial.println(r1.getCount());
  // Serial.println(r2.getCount());
  // Serial.println(r3.getCount());
  // Serial.println(r4.getCount());
  // int startTime = millis();
  // int duration = 0;
  // if (s == 1) {
    r1.turnRed();
    r2.turnRed();
    r3.turnRed();
    r4.turnRed();

  //   while (duration < 2000) {
  //     duration = millis() - startTime;
  //     if(duration%1000==0){
  //       Serial.println(duration);
  //     }
  // r1.Sense();
  // r2.Sense();
  // r3.Sense();
  // r4.Sense();
  //   }
  //   r1.Sense();
  //   r2.Sense();
  //   r3.Sense();
  //   r4.Sense();

  // Serial.println(r1.getCount());
  //   Serial.println(r2.getCount());
  //   Serial.println(r3.getCount());
  //   Serial.println(r4.getCount());
  //   s = 2;
  // }
  c.control_algo(r1, r2, r3, r4);

  // int startTime = millis();
  // int duration = 0;
  // Serial.println("red");
  // while (duration < 5000) {
    // r1.turnRed();
    // r3.turnRed();
    // r1.Sense();
    // r3.Sense();
    // c.control_algo(r1, r2, r3, r4);
    // Serial.println(temp);
    // duration = millis() - startTime;
  // }
  // Serial.println("green");
  // while (duration < 10000) {
  //   r1.turnGreen();
  //   r1.Sense();
  //   int temp = r1.getCount();
  //   Serial.println(temp);
  //   duration = millis() - startTime;
  // }
  // r1.setCount(5);
  // int temp = c.control(r1);
  // Serial.println(temp);
}