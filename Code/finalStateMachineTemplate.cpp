#include <Arduino.h>

const uint32_t NoStateChangeMax = 10000000; // this may need to be in millions!
const uint32_t WaitForReverse = 5000;
const uint32_t WaitForSpin = 5000;

void setup()
{
}

void loop()
{
  static uint32_t waitCount = 0;
  static uint32_t noStateChange = 0;
  // check seeBallFlag
  // check haveBallFlag
  // check seeGoalFlag
  // the onLineFlag will be changed via ISR

  // check the flags before running state machine by commenting out the state machine (select all lines then ctrl+/) and uncommenting the serial prints below (highlight just those lines then ctrl+/)
  // note the states may not clear but you can check them one by one and reset if need be
  // serial.print("seeBallFlag: ");
  // serial.print(seeBallFlag);
  // serial.print(" haveBallFlag: ");
  // serial.print(haveBallFlag);
  // serial.print(" seeGoalFlag: ");
  // serial.print(seeGoalFlag);
  // serial.print(" onLineFlag: ");
  // serial.println(onLineFlag);

  // now the state machine!
  if (robotState != SPIN_RIGHT_STATE && !seeBallFlag && !onLineFlag && !haveBallFlag) // if see ball and don't have ball and not on line
  {
    spinRight();
  }
  else if (robotState != FORWARD_STATE && seeBallFlag && !onLineFlag && !haveBallFlag) // if see ball and don't have ball and not on line
  {
    forward();
  }
  else if (robotState != SPIN_RIGHT_STATE && haveBallFlag && !seeGoalFlag && !onLineFlag) // if have ball and don't see goal and not on line
  {
    spinRight();
  }
  else if (robotState != FORWARD_STATE && seeGoalFlag && !onLineFlag) // if have ball and see goal and not on line
  {
    forward();
  }
  else if (onLineFlag || noStateCount > NoStateChangeMax) // if you ever see the line
  {

    // reset all states so you can still check if you're going to hit line while moving
    onLineFlag = noStateCount = seeBallFlag = seeGoalFlag = haveBallFlag = 0;
    // get the robot to move somewhere else
    reverse();
    while (!onLine && waitCount < WaitForReverse)
    {
      waitCount++;
      delay(1); // a small delay here may be needed unless waitCount is sufficient - can loop 4,294,967,295 times!
    }
    spinRight();
    waitCount = 0;
    while (!onLine && waitCount < WaitForReverse)
    {
      waitCount++;
      delay(1);
    }
    waitCount = 0;
  }
  else
  {
    noStateCount++;
  }
}
