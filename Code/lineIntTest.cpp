/*
This will use the builtInLed to test the hardware interrupt. If the bot is on the line, it will light the LED
for 2 seconds and then clear the LineState flag.
*/

#include <Arduino.h>

//make sure these pin constants are correct!
const uint8_t BuiltInLed = 0;
const uint8_t LinePin = 0; // pin 2 == int channel 0 | pin 3 == int channel 1

volatile bool lineStateFlag = 0;

void changeLineState();

void setup()
{
  pinMode(BuiltInLed, OUTPUT);

  attachInterrupt(0, changeLineState, FALLING); // change the trigger to make it trigger on the first edge of the tape!
}

void loop()
{
  if (lineStateFlag)
  {
    digitalWrite(BuiltInLed, HIGH);
    delay(2000);
    lineState = 0;
  }
  else
  {
    digitalWrite(BuiltInLed, LOW);
  }
}

void changeLineState()
{
  lineStateFlag = 1;
}