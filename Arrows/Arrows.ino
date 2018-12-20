//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 ***** Please set the number of devices you have *****
 But the maximum default of 8 MAX72XX wil also work.
 */
LedControl lc=LedControl(12,11,10,8);
int arrows=0;
int arrowt=75;

/* 
 This time we have more than one device. 
 But all of them have to be initialized 
 individually.
 */
void setup() {
  //we have already set the number of devices when we created the LedControl
  int devices=lc.getDeviceCount();
  //we have to init all devices in a loop
  for(int address=0;address<devices;address++) {
    /*The MAX72XX is in power-saving mode on startup*/
    lc.shutdown(address,false);
    /* Set the brightness to a medium values */
    lc.setIntensity(address,8);
    /* and clear the display */
    lc.clearDisplay(address);
  }
}

void loop()
{ 
  while(arrows<=4)
{
  lc.setRow(arrows,0,B00110000);
  lc.setRow(arrows,1,B01100000);
  lc.setRow(arrows,2,B11000000);
  lc.setRow(arrows,3,B10000001);
  lc.setRow(arrows,4,B10000001);
  lc.setRow(arrows,5,B11000000);
  lc.setRow(arrows,6,B01100000);
  lc.setRow(arrows,7,B00110000);
  arrows++;
}
arrows=0;
  delay(arrowt);
  while(arrows<=4)
{
  lc.setRow(arrows,0,B01100000);
  lc.setRow(arrows,1,B11000000);
  lc.setRow(arrows,2,B10000001);
  lc.setRow(arrows,3,B00000011);
  lc.setRow(arrows,4,B00000011);
  lc.setRow(arrows,5,B10000001);
  lc.setRow(arrows,6,B11000000);
  lc.setRow(arrows,7,B01100000);
  arrows++;
}
arrows=0;
delay(arrowt);
  while(arrows<=4)
{
  lc.setRow(arrows,0,B11000000);
  lc.setRow(arrows,1,B10000001);
  lc.setRow(arrows,2,B00000011);
  lc.setRow(arrows,3,B00000110);
  lc.setRow(arrows,4,B00000110);
  lc.setRow(arrows,5,B00000011);
  lc.setRow(arrows,6,B10000001);
  lc.setRow(arrows,7,B11000000);
  arrows++;
}
arrows=0;
  delay(arrowt);
  while(arrows<=4)
{
  lc.setRow(arrows,0,B10000001);
  lc.setRow(arrows,1,B00000011);
  lc.setRow(arrows,2,B00000110);
  lc.setRow(arrows,3,B00001100);
  lc.setRow(arrows,4,B00001100);
  lc.setRow(arrows,5,B00000110);
  lc.setRow(arrows,6,B00000011);
  lc.setRow(arrows,7,B10000001);
  arrows++;
}
arrows=0;
  delay(arrowt);
  while(arrows<=4)
{
  lc.setRow(arrows,0,B00000011);
  lc.setRow(arrows,1,B00000110);
  lc.setRow(arrows,2,B00001100);
  lc.setRow(arrows,3,B00011000);
  lc.setRow(arrows,4,B00011000);
  lc.setRow(arrows,5,B00001100);
  lc.setRow(arrows,6,B00000110);
  lc.setRow(arrows,7,B00000011);
  arrows++;
}
arrows=0;
  delay(arrowt);
  while(arrows<=4)
{
  lc.setRow(arrows,0,B00000110);
  lc.setRow(arrows,1,B00001100);
  lc.setRow(arrows,2,B00011000);
  lc.setRow(arrows,3,B00110000);
  lc.setRow(arrows,4,B00110000);
  lc.setRow(arrows,5,B00011000);
  lc.setRow(arrows,6,B00001100);
  lc.setRow(arrows,7,B00000110);

  arrows++;
}
arrows=0;
  delay(arrowt);
  while(arrows<=4)
{
  lc.setRow(arrows,0,B00001100);
  lc.setRow(arrows,1,B00011000);
  lc.setRow(arrows,2,B00110000);
  lc.setRow(arrows,3,B01100000);
  lc.setRow(arrows,4,B01100000);
  lc.setRow(arrows,5,B00110000);
  lc.setRow(arrows,6,B00011000);
  lc.setRow(arrows,7,B00001100);
  arrows++;
}
arrows=0;
  delay(arrowt);
  while(arrows<=4)
{
  lc.setRow(arrows,0,B00011000);
  lc.setRow(arrows,1,B00110000);
  lc.setRow(arrows,2,B01100000);
  lc.setRow(arrows,3,B11000000);
  lc.setRow(arrows,4,B11000000);
  lc.setRow(arrows,5,B01100000);
  lc.setRow(arrows,6,B00110000);
  lc.setRow(arrows,7,B00011000);
  arrows++;
}
arrows=0;
delay(arrowt);
}
