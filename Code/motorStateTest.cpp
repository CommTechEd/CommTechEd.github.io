/*
This will test all the motor states of your robot. Prop the robot up and you should see the state printed out
and motors turning in the correct directions.

Once edited and tested, you may use this program for all of your unit tests on the Nano.
*/

#include <Arduino.h>

// Please make sure your pin constants are correct
const uint8_t LeftMotorPin1 = 0;
const uint8_t LeftMotorPin2 = 0;
const uint8_t RightMotorPin1 = 0;
const uint8_t RightMotorPin2 = 0;

// adjust this global constant to make sure your motor stops completely before changing state.
const uint8_t MotorStopDelay = 100;

// global variables
uint8_t robotState = 0;

// define the robot state macros so you don't have to remember
#define STOP_STATE 0
#define FORWARD_STATE 1
#define REVERSE_STATE 2
#define SPIN_RIGHT_STATE 3
#define SPIN_LEFT_STATE 4

void stopBot();
void forward();
void reverse();
void spinLeft();
void spinRight();

void setup()
{
  //set all the rest of your MotorPins to OUTPUTs
  pinMode(LeftMotorPin1, OUTPUT);

  Serial.begin(9600);

  forward();
  Serial.print("Forward State: ");
  Serial.println(robotState);
  delay(2000);

  reverse();
  Serial.print("Reverse State: ");
  Serial.println(robotState);
  delay(2000);

  spinLeft();
  Serial.print("spinLeft State: ");
  Serial.println(robotState);
  delay(2000);

  spinRight();
  Serial.print("spinRight State: ");
  Serial.println(robotState);
  delay(2000);

  stopBot();
  Serial.print("Stop State: ");
  Serial.println(robotState);
  delay(2000);
}

void loop()
{
}

void stopBot()
{
  
}

void forward()
{
  //make sure you stop for some time before changing state
  stopBot();
  delay(MotorStopDelay);

  //set the motor pins correctly
  digitalWrite(LeftMotorPin1, HIGH);
  digitalWrite(LeftMotorPin2, HIGH);
  digitalWrite(RightMotorPin1, HIGH);
  digitalWrite(RightMotorPin2, HIGH);

  //don't forget to change the robot state
  robotState = FORWARD_STATE;
}

void reverse()
{
}

void spinLeft()
{
}

void spinRight()
{
}