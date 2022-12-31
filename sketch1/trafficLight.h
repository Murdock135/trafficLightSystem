#include "road.h"


class trafficLight : public road {
  int pin;  //any of the TrafficLight output pins
public:
  trafficLight(int pin=0): pin(pin) {}
  void turnOn();
  void turnOff();
};

void trafficLight::turnOn() {
  digitalWrite(pin, HIGH);
}

void trafficLight::turnOff() {
  digitalWrite(pin, HIGH);
}
