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
unsigned long delaytime=40;
int column=0;
int body=0;

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
  lc.setColumn(0,0,B00001000);
  delay(delaytime);
  lc.setColumn(0,1,B00001000);
  delay(delaytime);
  lc.setColumn(0,2,B00001000);
  delay(delaytime);
  lc.setColumn(0,3,B00001000);
  delay(delaytime);
  lc.setColumn(0,4,B00001000);
  delay(delaytime);
  lc.setColumn(0,5,B00001000);
  delay(delaytime);
  lc.setColumn(0,6,B00001000);
  delay(delaytime);
  lc.setColumn(0,7,B00001000);
  delay(delaytime);
  lc.setColumn(1,0,B00001000);
  delay(delaytime);
  lc.setColumn(1,1,B00001000);
  delay(delaytime);
  lc.setColumn(1,2,B00001000);
  delay(delaytime);
  lc.setColumn(1,3,B00001000);
  delay(delaytime);
  lc.setColumn(1,4,B00001000);
  delay(delaytime);
  lc.setColumn(1,5,B00001100);
  delay(delaytime);
  lc.setColumn(1,6,B00000110);
  delay(delaytime);
  lc.setColumn(1,7,B00000011);
  delay(delaytime);
  lc.setColumn(2,0,B00000011);
  delay(delaytime);
  lc.setColumn(2,1,B00000110);
  delay(delaytime);
  lc.setColumn(2,2,B00001100);
  delay(delaytime);
  lc.setColumn(2,3,B00011000);
  delay(delaytime);
  lc.setColumn(2,4,B00110000);
  delay(delaytime);
  lc.setColumn(2,5,B01100000);
  delay(delaytime);
  lc.setColumn(2,6,B11000000);
  delay(delaytime);
  lc.setColumn(2,7,B11000000);
  delay(delaytime);
  lc.setColumn(3,0,B01100000);
  delay(delaytime);
  lc.setColumn(3,1,B00110000);
  delay(delaytime);
  lc.setColumn(3,2,B00010000);
  delay(delaytime);
  lc.setColumn(3,3,B00010000);
  delay(delaytime);
  lc.setColumn(3,4,B00010000);
  delay(delaytime);
  lc.setColumn(3,5,B00010000);
  delay(delaytime);
  lc.setColumn(3,6,B00010000);
  delay(delaytime);
  lc.setColumn(3,7,B00010000);
  delay(delaytime);
  lc.setColumn(4,0,B00010000);
  delay(delaytime);
  lc.setColumn(4,1,B00010000);
  delay(delaytime);
  lc.setColumn(4,2,B00010000);
  delay(delaytime);
  lc.setColumn(4,3,B00010000);
  delay(delaytime);
  lc.setColumn(4,4,B00010000);
  delay(delaytime);
  lc.setColumn(4,5,B00010000);
  delay(delaytime);
  lc.setColumn(4,6,B00010000);
  delay(delaytime);
  lc.setColumn(4,7,B00010000);
  delay(delaytime);
  column=0;
  body=0;
  delay(1000);
  while (body<=4)
  {
    while (column<=7)
    {
      lc.setColumn(body,column,B00000000);
      column++;
      delay(delaytime);
    }
    column=0;
    body++;
  }
delay(1000);
}
