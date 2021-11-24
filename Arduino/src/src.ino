 /*************************************************************************
* File Name   : src.ino
* Author      : Richard Loong
* Updated     : Richard Loong
* Version     : v0.0.1
* Date        : 24/11/2021
* Description : Source Code
**************************************************************************/ 

#include <ServoTimer2.h>
#include <EnableInterrupt.h>
#include <Wire.h>

#define THROTTLE_PIN  9
#define STEERING_PIN 10
#define STEERING_PIN_OUT 6

volatile int pwmThrottle;
volatile unsigned long prevTimeThrottle = 0;
volatile int pwmSteering;
volatile unsigned long prevTimeSteering = 0;

ServoTimer2 steeringOut;

void setup() {
  Serial.begin(19200);
  //enableInterrupt(THROTTLE_PIN, risingThrottle, RISING);
  enableInterrupt(STEERING_PIN, risingSteering, RISING);
  steeringOut.attach(STEERING_PIN_OUT);  
}
 
void loop() {
  delay(33); // 30 FPS
  //Serial.print(pwmThrottle);
  //Serial.print("\t");
  
  if(pwmSteering<1072){
    pwmSteering = 1072;
  }
  if(pwmSteering>2012){
    pwmSteering = 2012;
  }
  steeringOut.write(pwmSteering);
  Serial.println(pwmSteering);
}
