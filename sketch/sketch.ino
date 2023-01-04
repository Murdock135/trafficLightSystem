#include "road.h"
#include "trafficLight.h"
using namespace std;
void control();


//set up roads
road one, two, three, four;

void setup() {
  Serial.begin(9600);

  //call all setups here
  one.setup(1, 2, int leftSensor, int rightSensor);
  two.setup(3, 4, int leftSensor, int rightSensor);
  three.setup(5, 6, int leftSensor, int rightSensor);
  four.setup(7, 8, int leftSensor, int rightSensor);
}

void loop() {
  one.loop();
  two.loop();
  three.loop();
  four.loop();

  control();

  delay(3000);
}

void control() {
  Serial.println("Your code is working");
}
