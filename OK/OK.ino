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
int delaytime1=200;
int OKc=0;
int OKs=1;
int OKt=0;
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
  lc.setColumn(2,1,B11111111);
  lc.setColumn(2,6,B11111111);
  delay(delaytime1);
  lc.setColumn(2,0,B11111111);
  lc.setColumn(2,7,B11111111);
  delay(delaytime1);
  lc.setColumn(1,7,B11111111);
  lc.setColumn(3,0,B11111111);
  delay(delaytime1);
  lc.setColumn(1,6,B10000001);
  lc.setColumn(3,1,B00011000);
  delay(delaytime1);
  lc.setColumn(1,5,B10000001);
  lc.setColumn(3,2,B00111100);
  delay(delaytime1);
  lc.setColumn(1,4,B10000001);
  lc.setColumn(3,3,B01111110);
  delay(delaytime1);
  lc.setColumn(1,3,B11111111);
  lc.setColumn(3,4,B01111110);
  delay(delaytime1);
  lc.setColumn(1,2,B11111111);
  lc.setColumn(3,5,B11100111);
  delay(delaytime1);
  lc.setColumn(1,1,B11111111);
  lc.setColumn(3,6,B11000011);
  delay(delaytime1);
  lc.setColumn(3,7,B10000001);
  delay(1000);
  while (OKt<=5)
  {
    
    lc.setRow(1,0,B01111111);
    lc.setRow(1,1,B01110001);
    lc.setRow(1,2,B01110001);
    lc.setRow(1,3,B01110001);
    lc.setRow(1,4,B01110001);
    lc.setRow(1,5,B01110001);
    lc.setRow(1,6,B01110001);
    lc.setRow(1,7,B01111111);
    lc.setRow(2,0,B11000011);
    lc.setRow(2,1,B11000011);
    lc.setRow(2,2,B11000011);
    lc.setRow(2,3,B11000011);
    lc.setRow(2,4,B11000011);
    lc.setRow(2,5,B11000011);
    lc.setRow(2,6,B11000011);
    lc.setRow(2,7,B11000011);
    lc.setRow(3,0,B10000111);
    lc.setRow(3,1,B10011110);
    lc.setRow(3,2,B10111100);
    lc.setRow(3,3,B11111000);
    lc.setRow(3,4,B11111000);
    lc.setRow(3,5,B10111100);
    lc.setRow(3,6,B10011110);
    lc.setRow(3,7,B10000111);
    delay(2000);
    while (OKs<=3)
    {
      while (OKc<=7)
      {
        lc.setRow(OKs,OKc,0);
        OKc++;
      }
      OKs++;
      OKc=0;
    }
    OKs=0;
    delay(1000);
    OKt++;
  }
  OKt=0;
}
