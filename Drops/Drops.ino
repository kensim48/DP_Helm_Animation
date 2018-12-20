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
unsigned long delaytime=500;
int rainS=0;
int rainR[40]={0,0,0,0,0,-1,-1,-1,-1,-1,-2,-2,-2,-2,-2,-3,-3,-3,-3,-3,-4,-4,-4,-4,-4,-5,-5,-5,-5,-5,-6,-6,-6,-6,-6,-7,-7,-7,-7,-7};
int rainON[40];
int rainnum=0;
int firsttime=1;
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
}

void loop()
{
  if (firsttime==1)
  {
    while (rainnum<=39)
    {
      while (rainS<=4)
      {
        rainON[rainnum]=random(1,256);
        lc.setRow(rainS,rainR[rainnum],rainON[rainnum]);
        rainnum++;
        rainS++;
      }
      rainS=0;
    }
   rainnum=0;
  }
  firsttime=0;
  while (rainnum<=39)
    {
      while (rainS<=4)
      {
        rainR[rainnum]++;
        if (rainR[rainnum]==8)
        {
          rainR[rainnum]=0;
          rainON[rainnum]=random(1,256);
        }
        lc.setRow(rainS,rainR[rainnum],rainON[rainnum]);
        rainnum++;
        rainS++;
      }
      rainS=0;
    }
   rainnum=0;
   delay(275);
}
