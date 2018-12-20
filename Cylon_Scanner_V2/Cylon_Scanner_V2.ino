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

int CylonON=0;
int CylonOFF=-3;
int CylonSON=0;
int CylonSOFF=0;

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
   while (CylonON<=7 && CylonSON<=4)
      {
        lc.setColumn(CylonSON,CylonON,B11111111);
        lc.setColumn(CylonSOFF,CylonOFF,B00000000);
        CylonOFF++;
        CylonON++;
        if (CylonON>7)
        {
          CylonSON++;
          CylonON=0;
        }
        if (CylonOFF>7)
        {
          CylonSOFF++;
          CylonOFF=0;
        }
        delay(22);
      }
      CylonON=4;
      CylonOFF=7;
      CylonSON=4;
      CylonSOFF=4;
      while (CylonON>=0 && CylonSON>=0)
      {
        lc.setColumn(CylonSON,CylonON,B11111111);
        lc.setColumn(CylonSOFF,CylonOFF,B00000000);
        CylonOFF--;
        CylonON--;
        if (CylonON<0)
        {
          CylonSON--;
          CylonON=7;
        }
        if (CylonOFF<0)
        {
          CylonSOFF--;
          CylonOFF=7;
        }
        delay(22);
      }
      CylonON=3;
      CylonOFF=0;
      CylonSON=0;
      CylonSOFF=0;
}
