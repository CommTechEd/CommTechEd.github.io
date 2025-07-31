/*
This will use the builtinled to test if the proximity sensor is working.
*/

#include <Arduino.h>
#include <Wire.h>

//define all the I2C address and register addresses for proximity sensor
#define APDS9960_ADDRESS 0x00
#define ENABLE_REG 0x00
#define PDAT_REG 0x00

//define the register pins
#define ENABLE_PON 0x00
#define ENABLE_PEN 0x00

//just to make it easier to remember
#define ERROR 1
#define NO_ERROR 0

//make sure these pin constants are correct!
const uint8_t BuiltInLed = 0;
const uint16_t TimeoutMax = 300;
const uint8_t ProxThresh = 0;

bool haveBallFlag = 0;

//define functions to use the proximity sensors
bool apds9960Begin();
uint8_t proxRead();


void setup()
{
  pinMode(BuiltInLed, OUTPUT);
  Wire.begin();
  
  //flash LED if apds9960 doesn't begin
  while(!apds9960Begin())
  {
    digitalWrite(BuiltInLed, HIGH);
    delay(200);
    digitalWrite(BuiltInLed, LOW);
    delay(200);
  }

}

void loop()
{
  //set the haveBallFlag if the proximith sensor reads above the threshold
  if(proxRead() > ProxThresh)
  {
    haveBallFlag = 1;
  }
  else
  {
    //this may dim the light if your program is reading faster than camera can read
    //clearing the seeBallFlag may not be necessary for your final program until after it attempts to score a goal.
    haveBallFlag = 0;
  }

  //turn on LED if camera sees the ball
  digitalWrite(BuiltInLed, haveBallFlag);
}

bool apds9960Begin()
{
  //set the bits in the enable register to power on and enable proximity
  //return an error if the transmisison doesn't work
  Wire.beginTransmission(APDS9960_ADDRESS);
  Wire.write(ENABLE_REG);
  Wire.write(ENABLE_PON | ENABLE_PEN);
  if(Wire.endtransmission())
  {
    return ERROR;
  }
  return NO_ERROR;
}

uint8_t proxRead()
{
  static uint16_t timeout = 0;
  timeout = 0;
  //write what register you want to read from first!

  //request from with a time out so program doesn't lock up
  Wire.requestFrom(APDS9960_ADDRESS, 1);
  while(!Wire.available())
  {
    timeout++
    if(timeout > TimeoutMax)
    {
      return ERROR;
    }
  }
  return Wire.read();
}