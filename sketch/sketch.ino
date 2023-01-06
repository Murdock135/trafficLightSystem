#include "road.h"
#include "trafficLight.h"
#include "controller.h"
using namespace std;

void control();
int calcDensity(road, road);
long int greenTime(int);


//set up roads
road r1("r1", 1, 2, 9);
road r2("r2", 3, 4, 10);
road r3("r3", 5, 6, 11);
road r4("r4", 7, 8, 12);
controller c;
int yellowDuration = 500;

void setup() {
  Serial.begin(9600);
  r1.red();
  r2.red();
  r3.red();
  r4.red();
}

int i = 1;
void loop() {
  r1.loop();
  r2.loop();
  r3.loop();
  r4.loop();
  long int programStart = millis();
  long int Duration = 0;
  if (i == 1) {
    while (Duration <= 2000) {
      Duration = millis() - programStart;
    }
  }
  i = 2;
  c.controlAlgorithm(r1, r2, r3, r4);
}
