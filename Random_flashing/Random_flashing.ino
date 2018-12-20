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
int times;
int Matrixn;
int colN;
int rowN;
int firsttime;
int randomN;


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
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop()
{
  if (firsttime=1)
  {
    while (times<=400)
    {
      Matrixn=random(0,5);
      colN=random(0,8);
      rowN=random(0,8);
      lc.setLed(Matrixn,rowN,colN,true);
      times++;
    }
  }
  while (randomN<=2)
  {
    firsttime=0;
    Matrixn=random(0,5);
    colN=random(0,8);
    rowN=random(0,8);
    lc.setLed(Matrixn,rowN,colN,true);
    randomN++;
  }
  randomN=0;
  Matrixn=random(0,5);
  colN=random(0,8);
  rowN=random(0,8);
  lc.setLed(Matrixn,rowN,colN,false);
  delay(1);
}
