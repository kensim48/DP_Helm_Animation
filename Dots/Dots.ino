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
LedControl lc=LedControl(12,11,10,1);

int dotsR=2;
long dotsdelay=150;
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
  while (dotsR<=4)
  {
    lc.setRow(0,dotsR,B11100000);
    lc.setRow(4,dotsR,B00000111);
    dotsR++;
  }
  dotsR=2;
  delay(dotsdelay);
  while (dotsR<=4)
  {
    lc.setRow(0,dotsR,B11101110);
    lc.setRow(4,dotsR,B01110111);
    dotsR++;
  }
  dotsR=2;
  delay(dotsdelay);
  while (dotsR<=4)
  {
    lc.setRow(1,dotsR,B11100000);
    lc.setRow(3,dotsR,B00000111);
    dotsR++;
  }
  dotsR=2;
  delay(dotsdelay);
  while (dotsR<=4)
  {
    lc.setRow(1,dotsR,B11101110);
    lc.setRow(3,dotsR,B01110111);
    dotsR++;
  }
  dotsR=2;
  delay(dotsdelay);
  while (dotsR<=4)
  {
    lc.setRow(2,dotsR,B11100111);
    dotsR++;
  }
  dotsR=2;
  delay(1000);
  //
  while (dotsR<=4)
  {
    lc.setRow(0,dotsR,B00001110);
    lc.setRow(4,dotsR,B01110000);
    dotsR++;
  }
  dotsR=2;
  delay(dotsdelay);
  while (dotsR<=4)
  {
    lc.setRow(0,dotsR,B00000000);
    lc.setRow(4,dotsR,B00000000);
    dotsR++;
  }
  dotsR=2;
  delay(dotsdelay);
  while (dotsR<=4)
  {
    lc.setRow(1,dotsR,B00001110);
    lc.setRow(3,dotsR,B01110000);
    dotsR++;
  }
  dotsR=2;
  delay(dotsdelay);
  while (dotsR<=4)
  {
    lc.setRow(1,dotsR,B00000000);
    lc.setRow(3,dotsR,B00000000);
    dotsR++;
  }
  dotsR=2;
  delay(dotsdelay);
  while (dotsR<=4)
  {
    lc.setRow(2,dotsR,B00000000);
    dotsR++;
  }
  dotsR=2;
  delay(dotsdelay);
}
