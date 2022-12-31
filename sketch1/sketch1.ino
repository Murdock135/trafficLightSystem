#include "road.h"
#include "trafficLight.h"
void control();

//define output pins for sensors later when sensors have been bought
//sensors sense each car's passing.
int Sensor1lpin;
int Sensor1rpin;
int Sensor2lpin;
int Sensor2rpin;
int Sensor3lpin;
int Sensor3rpin;
int Sensor4lpin;
int Sensor4rpin;
int TrafficLightOutput_1l = 9;
int TrafficLightOutput_1r = 9;
int TrafficLightOutput_2l = 9;
int TrafficLightOutput_2r = 9;
int TrafficLightOutput_3l = 9;
int TrafficLightOutput_3r = 9;
int TrafficLightOutput_4l = 9;
int TrafficLightOutput_4r = 9;

void setup() {
  // put your setup code here, to run once:

  pinMode(Sensor1lpin, INPUT);
  pinMode(Sensor1rpin, INPUT);
  pinMode(Sensor2lpin, INPUT);
  pinMode(Sensor2rpin, INPUT);
  pinMode(Sensor3lpin, INPUT);
  pinMode(Sensor3rpin, INPUT);
  pinMode(Sensor4lpin, INPUT);
  pinMode(Sensor4rpin, INPUT);
  pinMode(TrafficLightOutput_1l, OUTPUT);
  pinMode(TrafficLightOutput_1r, OUTPUT);
  pinMode(TrafficLightOutput_2l, OUTPUT);
  pinMode(TrafficLightOutput_2r, OUTPUT);
  pinMode(TrafficLightOutput_3l, OUTPUT);
  pinMode(TrafficLightOutput_3r, OUTPUT);
  pinMode(TrafficLightOutput_4l, OUTPUT);
  pinMode(TrafficLightOutput_4r, OUTPUT);


  Serial.begin(9600);
  //set up roads
  road oneL, oneR, twoL, twoR, threeL, threeR, fourL, fourR;
  //set up traffic Lights
  oneL.setupTL(int pin); 
  //keep all traffic Lights turned off first 
}

void loop() {
  // put your main code here, to run repeatedly:
  control();
}

void control(){
  
}
