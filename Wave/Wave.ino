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
int waveC[40]={0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7};
int waveS[40]={0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4};
int waveR[40]={0,1,2,3,4,5,6,7,7,6,5,4,3,2,1,0,0,1,2,3,4,5,6,7,7,6,5,4,3,2,1,0,0,1,2,3,4,5,6,7};
int waveK[40]={0};
int wavenum=0;
int wavereturn[40]={0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
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
  while (wavenum<40)
  {
      if (wavereturn[wavenum]==0)
      {
        if (waveR[wavenum]<=7)
        {
          lc.setLed(waveS[wavenum],waveR[wavenum]-1,waveC[wavenum],false);
          lc.setLed(waveS[wavenum],waveR[wavenum],waveC[wavenum],true);
          if (waveK[wavenum]==0)
          {
            waveR[wavenum]++;
            Serial.print(waveR[4]);
            if (waveR[wavenum]>7)
            {
              waveR[wavenum]=7;
              waveK[wavenum]=1;
            }
          }
          else
          {
              waveK[wavenum]=0;
              wavereturn[wavenum]=1;
          }
        }
    
      }
      else
      {
        if (waveR[wavenum]>=0)
        {
          lc.setLed(waveS[wavenum],waveR[wavenum]+1,waveC[wavenum],false);
          lc.setLed(waveS[wavenum],waveR[wavenum],waveC[wavenum],true);
          if (waveK[wavenum]==0)
          {
            waveR[wavenum]--;
            if (waveR[wavenum]<0)
            {
              waveR[wavenum]=0;
              waveK[wavenum]=1;
            }
          }
          else
          {
              waveK[wavenum]=0;
              wavereturn[wavenum]=0;
          }
        }
      }
      wavenum++;
  }
        wavenum=0;
  delay(10);
  Serial.print(wavenum);
}
