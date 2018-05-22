/*************************************************/
/* Program to turn stepper motor in up/down      */
/* direction in a fixed trial pattern            */
/* For use with the Adafruit Motor Shield v2     */
/* Motor connections:                            */
/* M1/3: green out/black in                      */
/* M2/4: red out/blue in                         */
/* M1/2: port 1                                  */
/* M3/4: port 2                                  */
/*************************************************/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_PWMServoDriver.h"

#define NSTEPS 200 // 1.8 deg / step => 1 revolution / 200 steps
#define SPEED 60 // in RPM
#define OPEN_PERIOD 5 // in s
#define CLOSED_PERIOD 10 // in s

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor * motor = AFMS.getStepper(NSTEPS, 2);

void setup() {
  Serial.begin(9600);
  AFMS.begin();  // create with the default frequency 1.6KHz
  motor->setSpeed(SPEED);
  Serial.print("Setup done...\n");
}

void loop() {
  // open curtain
  Serial.print("open curtain...\n");
  Serial.print("NSTEPS = ");
  Serial.print(NSTEPS);
  Serial.print("\n");
  //motor->setSpeed(5*SPEED);
  motor->step(2*NSTEPS, FORWARD, INTERLEAVE);
  
  // wait
  Serial.print("wait...\n");
  Serial.print("OPEN_PERIOD = ");
  Serial.print(OPEN_PERIOD);
  Serial.print("\n");
  delay(OPEN_PERIOD*1000);
  
  // close curtain
  Serial.print("close curtain...\n");
  //motor->setSpeed(SPEED);
  motor->step(NSTEPS, BACKWARD, SINGLE);

  // wait until next trial
  delay(CLOSED_PERIOD*1000);
}
