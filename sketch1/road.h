#include "Arduino.h"
#include "trafficLight.h"

class road : {
private:
  trafficLight tl;
protected:
  int carCount = 0;
public:
  int sensorPin;
  void setupTL(int pin);
  void senseCar();
};

void road::senseCar(){
  if(digitalRead(sensorPin)==LOW)
    ++carCount;
}

void road::setupTL(int pin){
  trafficLight newTL(pin);
  tl = newTL;
}