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

int tbON=0;
int tbOFF=-3;
int tbS=0;

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
  while (tbOFF<=7)
  {
    while (tbS<=4)
    {
      lc.setRow(tbS,tbON,B11111111);
      lc.setRow(tbS,tbOFF,B00000000);
      tbS++;
    }
    tbS=0;
    delay(65);
    tbOFF++;
    tbON++;
  }
  delay(700);
  tbON=0;
  tbOFF=-3;
}
