#include <Arduino.h>

void setup()
{
}

void loop()
{
  // check seeBallFlag
  // check haveBallFlag
  // check seeGoalFlag

  // if don't see ball and don't have ball and not on line
  {
    if (robotState != SPIN_RIGHT_STATE)
    {
      spinRight();
    }
  }

  // if see ball and don't have ball and not on line
  {
    if (robotState != FORWARD_STATE)
    {
      forward();
    }
  }

  // if have ball and don't see goal and not on line
  {
    if (robotState != SPIN_RIGHT_STATE)
    {
      spinRight();
    }
  }

  // if have ball and see goal and not on line
  {
    if (robotState != FORWARD_STATE)
    {
      forward();
    }
  }
  // else if on line
  {
    stopBot();
    delay(500);
    reverse();
    delay(2000);
  }
}
