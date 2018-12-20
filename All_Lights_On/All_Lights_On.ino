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
LedControl lc=LedControl(12,11,10,5);

/* we always wait a bit between updates of the display */
unsigned long delaytime=500;
int lightsonC=0;
int lightsonS=0;

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
    lc.setIntensity(address,3);
    /* and clear the display */
    lc.clearDisplay(address);
  }
}

void loop()
{ 
  lightsonC=0;
  lightsonS=0;
  while (lightsonS<=4)
  {
    while (lightsonC<=7)
    {
      lc.setColumn(lightsonS,lightsonC,B11111111);
      lightsonC++;
      delay(30);
    }
    lightsonC=0;
    lightsonS++;
  }
  delay(1000);
  while (lightsonS>=0)
  {
    while (lightsonC>=0)
    {
      lc.setColumn(lightsonS,lightsonC,B00000000);
      lightsonC--;
      delay(30);
    }
    lightsonC=7;
    lightsonS--;
  }
  delay(2000);
  lightsonC=7;
  lightsonS=4;
  while (lightsonS>=0)
  {
    while (lightsonC>=0)
    {
      lc.setColumn(lightsonS,lightsonC,B11111111);
      lightsonC--;
      delay(30);
    }
    lightsonC=7;
    lightsonS--;
  }
  delay(1000);
  while (lightsonS<=4)
  {
    while (lightsonC<=7)
    {
      lc.setColumn(lightsonS,lightsonC,B00000000);
      lightsonC++;
      delay(30);
    }
    lightsonC=0;
    lightsonS++;
  }
  delay(2000);
}
