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
int musicR[32]={7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7};
int musicC[32]={1,2,3,4,6,7,0,1,3,4,5,6,0,1,2,3,5,6,7,0,2,3,4,5,7,0,1,2,4,5,6,7};
int musicS[32]={0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,4,4};
int musicbarnum=0;
int randmusic;
int musicBarcounter=0;
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
    while (musicbarnum<32)
    {
      musicR[musicbarnum]=7;
      musicbarnum++;
    }
    firsttime=0;
     musicbarnum=0;
  }
  randmusic=random(0,4);
  while (musicBarcounter<=3)
  {
    lc.setLed(musicS[musicbarnum],musicR[musicbarnum],musicC[musicbarnum],true);
    lc.setLed(musicS[musicbarnum],musicR[musicbarnum]-1,musicC[musicbarnum],false);
    if (randmusic==1)
    {
      musicR[musicbarnum]++;
    }
    else if (randmusic==2)
    {
      musicR[musicbarnum]--;
    }
    if (musicR[musicbarnum]==8)
    {
      musicR[musicbarnum]=7;
    }
    if (musicR[musicbarnum]==-1)
    {
      musicR[musicbarnum]=0;
    }
    musicbarnum++;
    musicBarcounter++;
  }
  musicBarcounter=0;
  if (musicbarnum>31)
  {
    musicbarnum=0;
    musicBarcounter=0;
    delay(10);
  }
}
