//#include <SoftwareSerial.h>
//#include <Stepper.h>

/*************************************************************
Motor Shield Stepper Demo
by Randy Sarafan

For more information see:
https://www.instructables.com/id/Arduino-Motor-Shield-Tutorial/

*************************************************************/

//The pin breakdown is as follows:
//
//Function        Channel A   Channel B
//Direction       Digital 12  Digital 13
//Speed (PWM)     Digital 3   Digital 11
//Brake           Digital 9   Digital 8
//Current Sensing Analog 0    Analog 1

int delaylegnth = 10; //delay between single stepper steps
int speedy = 255;  //duty cycle (0-255), 255 means always on
int steps = 90; //sets the rotation time, standard: 60 steps; shaded 45
int updatedsteps;
int watchPin= 7;
int buttonState;
int updown=0; //1 is up

void setup() {
  
  //establish motor direction toggle pins
  pinMode(12, OUTPUT); //CH A -- HIGH = forwards and LOW = backwards???
  pinMode(13, OUTPUT); //CH B -- HIGH = forwards and LOW = backwards???
  
  //establish motor brake pins
  pinMode(9, OUTPUT); //brake (disable) CH A
  pinMode(8, OUTPUT); //brake (disable) CH B
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  
}

void loop(){

  
  digitalWrite(9, HIGH);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B
  digitalWrite(12, HIGH);   //Sets direction of CH A
  digitalWrite(13, HIGH);   //Sets direction of CH B

  updatedsteps=steps;
 
  int buttonState = digitalRead(watchPin);
  
  
 
//
//
////  digitalWrite(9, HIGH);  //ENABLE CH A
////  digitalWrite(8, HIGH); //DISABLE CH B
////
////  digitalWrite(12, HIGH);   //Sets direction of CH A
////  digitalWrite(13, HIGH);   //Sets direction of CH B
////
////delay(1000); //time between forward and backward movement
////updatedsteps=steps;

Serial.println(buttonState);
Serial.println('a');

if (buttonState==1 && updown==0)
 {
  Serial.println("updown = 0");
  while (updatedsteps>0)
 {
  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, HIGH);   //Sets direction of CH A
  analogWrite(3, speedy);   //Moves CH A
  
  delay(delaylegnth);
  
  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, LOW);   //Sets direction of CH B
  analogWrite(11, speedy);   //Moves CH B
  
  delay(delaylegnth);
  
  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, LOW);   //Sets direction of CH A
  analogWrite(3, speedy);   //Moves CH A
  
  delay(delaylegnth);
    
  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, HIGH);   //Sets direction of CH B
  analogWrite(11, speedy);   //Moves CH B
  
  delay(delaylegnth);

  updatedsteps=updatedsteps-1;
 }

 updown=1;
 }

updatedsteps=steps;
Serial.println(buttonState);
Serial.println('b');

 if (buttonState==0 && updown==1)
  {
Serial.println("updown = 1");

  while (updatedsteps>0)
 {
  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, HIGH);   //Sets direction of CH A
  analogWrite(3, speedy);   //Moves CH A
  
  delay(delaylegnth);
  
  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, HIGH);   //Sets direction of CH B
  analogWrite(11, speedy);   //Moves CH B
  
  delay(delaylegnth);
  
  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, LOW);   //Sets direction of CH A
  analogWrite(3, speedy);   //Moves CH A
  
  delay(delaylegnth);
    
  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, LOW);   //Sets direction of CH B
  analogWrite(11, speedy);   //Moves CH B
  
  delay(delaylegnth);

  updatedsteps=updatedsteps-1;

 }
   updown=0;
 }


} 

