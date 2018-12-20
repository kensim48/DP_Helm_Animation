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

int LazerON=0;
int LazerOFF=-2;
int LazerSON=0;
int LazerSOFF=0;

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
   while (LazerON<=7 && LazerSON<=4)
      {
        lc.setColumn(LazerSON,LazerON,B00011000);
        lc.setColumn(LazerSOFF,LazerOFF,B00000000);
        LazerOFF++;
        LazerON++;
        if (LazerON>7)
        {
          LazerSON++;
          LazerON=0;
        }
        if (LazerOFF>7)
        {
          LazerSOFF++;
          LazerOFF=0;
        }
        delay(5);
      }
      LazerON=5;
      LazerOFF=7;
      LazerSON=4;
      LazerSOFF=4;
      while (LazerON>=0 && LazerSON>=0)
      {
        lc.setColumn(LazerSON,LazerON,B00011000);
        lc.setColumn(LazerSOFF,LazerOFF,B00000000);
        LazerOFF--;
        LazerON--;
        if (LazerON<0)
        {
          LazerSON--;
          LazerON=7;
        }
        if (LazerOFF<0)
        {
          LazerSOFF--;
          LazerOFF=7;
        }
        delay(5);
      }
      LazerON=2;
      LazerOFF=0;
      LazerSON=0;
      LazerSOFF=0;
}
