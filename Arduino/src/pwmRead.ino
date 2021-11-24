 /*************************************************************************
* File Name   : pwmRead.ino
* Author      : Richard Loong
* Updated     : Richard Loong`
* Version     : v0.0.1
* Date        : 24/11/2021
* Description : Functions to read PWM pulses.
**************************************************************************/

void risingThrottle() {
  prevTimeThrottle = micros();
  enableInterrupt(THROTTLE_PIN, fallingThrottle, FALLING);
}
 
void fallingThrottle() {
  pwmThrottle = micros()-prevTimeThrottle;
  disableInterrupt(THROTTLE_PIN);
  enableInterrupt(THROTTLE_PIN, risingThrottle, RISING);
}

void risingSteering() {
  prevTimeSteering = micros();
  enableInterrupt(STEERING_PIN, fallingSteering, FALLING);
}
 
void fallingSteering() {
  pwmSteering = micros()-prevTimeSteering;
  disableInterrupt(STEERING_PIN);
  enableInterrupt(STEERING_PIN, risingSteering, RISING);
}