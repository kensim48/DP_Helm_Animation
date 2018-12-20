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
  lc.setRow(1,1,B00011100);
  lc.setRow(1,2,B00111110);
  lc.setRow(1,3,B01100011);
  lc.setRow(1,4,B01100011);
  lc.setRow(1,5,B00111110);
  lc.setRow(1,6,B00011100);
  //
  lc.setRow(3,1,B00111000);
  lc.setRow(3,2,B01111100);
  lc.setRow(3,3,B11000110);
  lc.setRow(3,4,B11000110);
  lc.setRow(3,5,B01111100);
  lc.setRow(3,6,B00111000);
  delay(2100);
  lc.setRow(1,1,B00000000);
  lc.setRow(1,2,B0000000);
  lc.setRow(1,3,B01111111);
  lc.setRow(1,4,B01111111);
  lc.setRow(1,5,B0000000);
  lc.setRow(1,6,B00000000);
  //
  lc.setRow(3,1,B00000000);
  lc.setRow(3,2,B0000000);
  lc.setRow(3,3,B11111110);
  lc.setRow(3,4,B11111110);
  lc.setRow(3,5,B0000000);
  lc.setRow(3,6,B00000000);
  delay(400);
}
