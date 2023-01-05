#include "road.h"
#include "trafficLight.h"
using namespace std;
void control();


//set up roads
road one(1, 2, 9);
road two(3, 4, 10);
road three(5, 6, 11);
road four(7, 8, 12);

void setup() {
  Serial.begin(9600);

  //call all setups here

  one.red();
  two.red();
  three.red();
  four.red();
}

void loop() {
  one.loop();
  two.loop();
  three.loop();
  four.loop();

  control();

}

void control() {
  if (one.getCount()+three.getCount() == two.getCount()+four.getCount()) {
    one.greenStraight();
    three.greenStraight();
    delay(5000);
    one.yellow();
    three.yellow();
  }
  if((one.getCount()==0)&&(two.getCount()==0)&&(three.getCount()==0)&&(four.getCount()==0)){
    one.greenStraightAndRight();
    delay(5000);
    one.yellow();
    delay(5000);
    one.red();
  }
}

