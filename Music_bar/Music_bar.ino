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
int levelaBit;
int levelbBit;
int levelcBit;
int leveldBit;
int leveleBit;
int levelfBit;
int levelgBit;
int levelhBit;
int levela;
int levelb;
int levelc;
int leveld;
int levele;
int levelf;
int levelg;
int levelh;
int randnum;
int first=1;

/* we always wait a bit between updates of the display */

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
    lc.setIntensity(address,2);
    /* and clear the display */
    lc.clearDisplay(address);
  }
  randomSeed(analogRead(0));
}

void loop()
{
  if (first==1)
  {
    levelaBit=random(1,8);
    levelbBit=random(1,8);
    levelcBit=random(1,8);
    leveldBit=random(1,8);
    leveleBit=random(1,8);
    levelfBit=random(1,8);
    levelgBit=random(1,8);
    levelhBit=random(1,8);
  }
  first=0;
  randnum=random(4);
  if (levela>8)
  {
    levela=levela-random(0,5);
  }
  else if (levela<1)
  {
    levela=levela+random(0,5);
  }
  else
  {
    if (randnum<=1)
    {
      levela++;
    }
    else if (randnum>2)
    {
      levela--;
    }
    else
    {
    }
  }
  switch (levela)
  {
    case 1:
    levelaBit=1;
    break;
    
    case 2:
    levelaBit=3;
    break;
    
    case 3:
    levelaBit=7;
    break;
    
    case 4:
    levelaBit=15;
    break;
    
    case 5:
    levelaBit=31;
    break;
    
    case 6:
    levelaBit=63;
    break;
    
    case 7:
    levelaBit=127;
    break;
    
    case 8:
    levelaBit=255;
    break;
  }
  lc.setColumn(0,0,levelaBit);
  lc.setColumn(0,1,levelaBit);
  lc.setColumn(0,2,levelaBit);
  lc.setColumn(0,3,levelaBit);
  lc.setColumn(0,4,levelaBit);
  delay(10);
  //
  randnum=random(4);
  if (levelb>8)
  {
    levelb=levelb-random(0,5);
  }
  else if (levelb<1)
  {
    levelb=levelb+random(0,5);
  }
  else
  {
    if (randnum<=1)
    {
      levelb++;
    }
    else if (randnum>2)
    {
      levelb--;
    }
    else
    {
    }
  }
  switch (levelb)
  {
    case 1:
    levelbBit=1;
    break;
    
    case 2:
    levelbBit=3;
    break;
    
    case 3:
    levelbBit=7;
    break;
    
    case 4:
    levelbBit=15;
    break;
    
    case 5:
    levelbBit=31;
    break;
    
    case 6:
    levelbBit=63;
    break;
    
    case 7:
    levelbBit=127;
    break;
    
    case 8:
    levelbBit=255;
    break;
  }
  lc.setColumn(0,5,levelbBit);
  lc.setColumn(0,6,levelbBit);
  lc.setColumn(0,7,levelbBit);
  lc.setColumn(1,0,levelbBit);
  lc.setColumn(1,1,levelbBit);
  delay(10);
  //
  randnum=random(4);
  if (levelc>8)
  {
    levelc=levelc-random(0,5);
  }
  else if (levelc<1)
  {
    levelc=levelc+random(0,5);
  }
  else
  {
    if (randnum<=1)
    {
      levelc++;
    }
    else if (randnum>2)
    {
      levelc--;
    }
    else
    {
    }
  }
  switch (levelc)
  {
    case 1:
    levelcBit=1;
    break;
    
    case 2:
    levelcBit=3;
    break;
    
    case 3:
    levelcBit=7;
    break;
    
    case 4:
    levelcBit=15;
    break;
    
    case 5:
    levelcBit=31;
    break;
    
    case 6:
    levelcBit=63;
    break;
    
    case 7:
    levelcBit=127;
    break;
    
    case 8:
    levelcBit=255;
    break;
  }
  lc.setColumn(1,2,levelcBit);
  lc.setColumn(1,3,levelcBit);
  lc.setColumn(1,4,levelcBit);
  lc.setColumn(1,5,levelcBit);
  lc.setColumn(1,6,levelcBit);
  delay(10);
  //
  randnum=random(4);
  if (leveld>8)
  {
    leveld=leveld-random(0,5);
  }
  else if (leveld<1)
  {
    leveld=leveld+random(0,5);
  }
  else
  {
    if (randnum<=1)
    {
      leveld++;
    }
    else if (randnum>2)
    {
      leveld--;
    }
    else
    {
    }
  }
  switch (leveld)
  {
    case 1:
    leveldBit=1;
    break;
    
    case 2:
    leveldBit=3;
    break;
    
    case 3:
    leveldBit=7;
    break;
    
    case 4:
    leveldBit=15;
    break;
    
    case 5:
    leveldBit=31;
    break;
    
    case 6:
    leveldBit=63;
    break;
    
    case 7:
    leveldBit=127;
    break;
    
    case 8:
    leveldBit=255;
    break;
  }
  lc.setColumn(1,7,leveldBit);
  lc.setColumn(2,0,leveldBit);
  lc.setColumn(2,1,leveldBit);
  lc.setColumn(2,2,leveldBit);
  lc.setColumn(2,3,leveldBit);
  delay(10);
  //
  randnum=random(4);
  if (levele>8)
  {
    levele=levele-random(0,5);
  }
  else if (levele<1)
  {
    levele=levele+random(0,5);
  }
  else
  {
    if (randnum<=1)
    {
      levele++;
    }
    else if (randnum>2)
    {
      levele--;
    }
    else
    {
    }
  }
  switch (levele)
  {
    case 1:
    leveleBit=1;
    break;
    
    case 2:
    leveleBit=3;
    break;
    
    case 3:
    leveleBit=7;
    break;
    
    case 4:
    leveleBit=15;
    break;
    
    case 5:
    leveleBit=31;
    break;
    
    case 6:
    leveleBit=63;
    break;
    
    case 7:
    leveleBit=127;
    break;
    
    case 8:
    leveleBit=255;
    break;
  }
  lc.setColumn(2,4,leveleBit);
  lc.setColumn(2,5,leveleBit);
  lc.setColumn(2,6,leveleBit);
  lc.setColumn(2,7,leveleBit);
  lc.setColumn(3,0,leveleBit);
  delay(10);
  //
  randnum=random(4);
  if (levelf>8)
  {
    levelf=levelf-random(0,5);
  }
  else if (levelf<1)
  {
    levelf=levelf+random(0,5);
  }
  else
  {
    if (randnum<=1)
    {
      levelf++;
    }
    else if (randnum>2)
    {
      levelf--;
    }
    else
    {
    }
  }
  switch (levelf)
  {
    case 1:
    levelfBit=1;
    break;
    
    case 2:
    levelfBit=3;
    break;
    
    case 3:
    levelfBit=7;
    break;
    
    case 4:
    levelfBit=15;
    break;
    
    case 5:
    levelfBit=31;
    break;
    
    case 6:
    levelfBit=63;
    break;
    
    case 7:
    levelfBit=127;
    break;
    
    case 8:
    levelfBit=255;
    break;
  }
  lc.setColumn(3,1,levelfBit);
  lc.setColumn(3,2,levelfBit);
  lc.setColumn(3,3,levelfBit);
  lc.setColumn(3,4,levelfBit);
  lc.setColumn(3,5,levelfBit);
  delay(10);
  //
  randnum=random(4);
  if (levelg>8)
  {
    levelg=levelg-random(0,5);
  }
  else if (levelg<1)
  {
    levelg=levelg+random(0,5);
  }
  else
  {
    if (randnum<=1)
    {
      levelg++;
    }
    else if (randnum>2)
    {
      levelg--;
    }
    else
    {
    }
  }
  switch (levelg)
  {
    case 1:
    levelgBit=1;
    break;
    
    case 2:
    levelgBit=3;
    break;
    
    case 3:
    levelgBit=7;
    break;
    
    case 4:
    levelgBit=15;
    break;
    
    case 5:
    levelgBit=31;
    break;
    
    case 6:
    levelgBit=63;
    break;
    
    case 7:
    levelgBit=127;
    break;
    
    case 8:
    levelgBit=255;
    break;
  }
  lc.setColumn(3,6,levelgBit);
  lc.setColumn(3,7,levelgBit);
  lc.setColumn(4,0,levelgBit);
  lc.setColumn(4,1,levelgBit);
  lc.setColumn(4,2,levelgBit);
  delay(10);
  //
  randnum=random(4);
  if (levelh>8)
  {
    levelh=levelh-random(0,5);
  }
  else if (levelh<1)
  {
    levelh=levelh+random(0,5);
  }
  else
  {
    if (randnum<=1)
    {
      levelh++;
    }
    else if (randnum>2)
    {
      levelh--;
    }
    else
    {
    }
  }
  switch (levelh)
  {
    case 1:
    levelhBit=1;
    break;
    
    case 2:
    levelhBit=3;
    break;
    
    case 3:
    levelhBit=7;
    break;
    
    case 4:
    levelhBit=15;
    break;
    
    case 5:
    levelhBit=31;
    break;
    
    case 6:
    levelhBit=63;
    break;
    
    case 7:
    levelhBit=127;
    break;
    
    case 8:
    levelhBit=255;
    break;
  }
  lc.setColumn(4,3,levelhBit);
  lc.setColumn(4,4,levelhBit);
  lc.setColumn(4,5,levelhBit);
  lc.setColumn(4,6,levelhBit);
  lc.setColumn(4,7,levelhBit);
  delay(10);
}
