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

int fileR=0;
int fileS=0;
int filenum=0;

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
  while (fileS<=4)
  {
    while (fileR<=7)
    {
      lc.setRow(fileS,fileR,B10001000);
      fileR++;
    }
    fileR=0;
    fileS++;
  }
  fileS=0;
  delay(150);
  while (fileS<=4)
  {
    while (fileR<=7)
    {
      lc.setRow(fileS,fileR,B01000100);
      fileR++;
    }
    fileR=0;
    fileS++;
  }
  fileS=0;
  delay(150);
  while (fileS<=4)
  {
    while (fileR<=7)
    {
      lc.setRow(fileS,fileR,B00100010);
      fileR++;
    }
    fileR=0;
    fileS++;
  }
  fileS=0;
  delay(150);
  while (fileS<=4)
  {
    while (fileR<=7)
    {
      lc.setRow(fileS,fileR,B00010001);
      fileR++;
    }
    fileR=0;
    fileS++;
  }
  fileS=0;
  delay(150);
}
