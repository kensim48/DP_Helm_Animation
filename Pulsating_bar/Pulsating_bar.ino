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
int num=0;
int rown=2;
int firsttime=1;
int intense = 0;
/* we always wait a bit between updates of the display */
unsigned long delaytime=500;

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
  Serial.begin(9600);
}

void loop()
{
  if (firsttime=1)
  {
    while (num<=7)
    {
      while (rown<=4)
      {
        lc.setRow(num,rown,B11111111);
        rown++;
      }
      rown=2;
      num++;
    }
  }
  firsttime=0;
  while (num<=7)
  {
    lc.setIntensity(num,intense);
    num++;
  }
  intense++;
  num=0;
  delay(150);
  Serial.print(intense);
  if (intense==14)
  {
    while (intense>=1)
    {
      while (num<=7)
      {
        lc.setIntensity(num,intense);
        num++;
      }
      intense--;
      delay(150);
      num=0;
    }
  }      
}
