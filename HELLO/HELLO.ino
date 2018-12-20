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
int helloT=300;
int helloS=0;
int helloR=0;

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
  lc.setRow(1,7,B10001001);
  lc.setRow(2,7,B11101110);
  lc.setRow(3,7,B11100111);
  delay(helloT);
  lc.setRow(1,6,B10001010);
  lc.setRow(2,6,B00000100);
  lc.setRow(3,6,B01001000);
  lc.setRow(4,6,B10000000);
  delay(helloT);
  lc.setRow(1,5,B10001011);
  lc.setRow(2,5,B11000100);
  lc.setRow(3,5,B01001000);
  lc.setRow(4,5,B10000000);
  delay(helloT);
  lc.setRow(1,4,B11111010);
  lc.setRow(2,4,B00100100);
  lc.setRow(3,4,B01001000);
  lc.setRow(4,4,B10000000);
  delay(helloT);
  lc.setRow(1,3,B10001001);
  lc.setRow(2,3,B11000100);
  lc.setRow(3,3,B01000111);
  delay(helloT);
  lc.setRow(1,2,B10001000);
  lc.setRow(2,2,B00000100);
  lc.setRow(3,2,B01000000);
  delay(helloT);
  lc.setRow(1,1,B10001000);
  lc.setRow(2,1,B00001100);
  lc.setRow(3,1,B11000000);
  delay(5000);
  while (helloS<=4)
  {
    while (helloR<=7)
    {
      lc.setRow(helloS,helloR,B00000000);
      helloR++;
    }
    helloR=0;
    helloS++;
  }
  helloS=0;
  helloR=0;
  delay(500);
}
