#include "road.h"
#include "trafficLight.h"
using namespace std;
void control();


//set up roads
road one("one" ,1, 2, 9);
road two("two" ,3, 4, 10);
road three("three" ,5, 6, 11);
road four("four" ,7, 8, 12);

void setup() {
  Serial.begin(9600);
  one.red();
  two.red();
  three.red();
  four.red();
}

int i = 1;
void loop() {
  one.loop();
  two.loop();
  three.loop();
  four.loop();
  if (i == 1) {
    delay(10000);
  }

  control();
  ++i;  
}

void control() {
  int pairOneThree = one.calcDensity() + three.calcDensity();
  int pairtwoFour = two.calcDensity() + four.calcDensity();
  int delay_time;

  if (((pairOneThree == pairtwoFour) && (pairOneThree != 0)) || (pairOneThree > pairtwoFour)) {
    //make one and three green (only straight)
    one.greenStraight();
    three.greenStraight();

    //compare delay time of the pair of roads and pick the larger one
    one.greenTime() > three.greenTime() ? delay_time = one.greenTime() : delay_time = three.greenTime();
    delay(delay_time);

    //make one three yellow
    one.yellow();
    three.yellow();

    delay(500);

    //make one and three red
    one.red();
    three.red();
  } else if (pairOneThree < pairtwoFour) {
    //make two and four green (only straight)
    two.greenStraight();
    four.greenStraight();

    two.greenTime() > four.greenTime() ? delay_time = two.greenTime() : delay_time = four.greenTime();
    delay(delay_time);

    //make two and four yellow
    two.yellow();
    four.yellow();

    delay(500);

    //make two and four red
    two.red();
    four.red();
  } else if ((one.getCount() == 0) && (two.getCount() == 0) && (three.getCount() == 0) && (four.getCount() == 0)) {
    one.greenStraight();  //keep road one green if every road is empty
  }
}
