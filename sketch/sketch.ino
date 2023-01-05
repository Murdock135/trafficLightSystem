#include "road.h"
#include "trafficLight.h"
using namespace std;
void control();
int calcDensity(road, road);
int greenTime(int);


//set up roads
road one("one", 1, 2, 9);
road two("two", 3, 4, 10);
road three("three", 5, 6, 11);
road four("four", 7, 8, 12);

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
    delay(20000);  //Buffer time to place marbles
  }

  control();
  ++i;
}

void control() {
  int pairOneThree = calcDensity(one, three);
  int pairTwoFour = calcDensity(two, four);

  if (((pairOneThree == pairTwoFour) && (pairOneThree != 0)) || (pairOneThree > pairTwoFour)) {
    //make one and three green (only straight)
    one.greenStraight();
    three.greenStraight();

    int delay_time = greenTime(pairOneThree);
    delay(delay_time);

    //make one three yellow
    one.yellow();
    three.yellow();

    delay(500);

    //make one and three red
    one.red();
    three.red();
  } else if (pairOneThree < pairTwoFour) {
    //make two and four green (only straight)
    two.greenStraight();
    four.greenStraight();

    int delay_time = greenTime(pairTwoFour);
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
  else if (total == 0)
    return 0;
}

int greenTime(int trafficDensity) {
  //no greentime for calcDensity==0
  if (trafficDensity == 1)
    return 3000;
  if (trafficDensity == 2)
    return 6000;
  if (trafficDensity == 3)
    return 8000;
}