#pragma once

class trafficLight {
  int pin;  //any of the TrafficLight output pins
public:
  trafficLight(int pin=0): pin(pin) {}
  void turnOn() {
    digitalWrite(pin, HIGH);
  }
  void turnOff() {
    digitalWrite(pin, LOW);
  }
};

/*
void trafficLight::turnOn() {
  digitalWrite(pin, HIGH);
}

void trafficLight::turnOff() {
  digitalWrite(pin, LOW);
}
*/