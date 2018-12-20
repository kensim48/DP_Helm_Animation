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
LedControl lc=LedControl(12,11,10,8);

/* we always wait a bit between updates of the display */
unsigned long delaytime=500;
int LEDcolumnF=0;
int LEDcolumnB=4;
int LEDback=0;
int subject=0;
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
  Serial.begin(9600);
}

void loop()
{
  Serial.print(LEDcolumnF);
  if (LEDback==0)//checks if Its forwards or backwards
  {
    
    if (LEDcolumnF<=7)//Check to change subject
    {
      lc.setColumn(subject,LEDcolumnF,B11111111);//turns on column
      if (LEDcolumnF<3)//checks if IC needs to switch something off from the last subject
      {
        if (subject>0)
        {
          if (LEDcolumnF==0)
          {
            lc.setColumn(subject-1,5,B00000000);
          }
          if (LEDcolumnF==1)
          {
            lc.setColumn(subject-1,6,B00000000);
          }
          if (LEDcolumnF==2)
          {
            lc.setColumn(subject-1,7,B00000000);
          }
        }
      }
      else
      {
        lc.setColumn(subject,LEDcolumnF-3,B00000000);//if nothing to switch off from last subject
      }
      LEDcolumnF++;//increases column in normal circumstances
      delay(10);
    }
    else//if column=8(exceeded)
    {
      //resets column if subject increases
      if (subject<4)
      {
        subject++;
        LEDcolumnF=0;
      }
      else
      {
        LEDback=1;//if subject increases over the limit of the 5 matrices, program will change it to back mode
        LEDcolumnB=4;
      }
    }
  }
  else//circuit is on Back mode
  {
    if (LEDcolumnB>=0) //Checks if Display is on its last column
    {
      if (subject>=0)//checks if display is on has exceeded itss last subject
      {
        lc.setColumn(subject,LEDcolumnB,B11111111);//if not, it will switch on one column, and switch off another
        if (LEDcolumnB>4)//checks if column needed to be swtiched off is in the same subject
        {
            if (subject>=0)
            {
              {
                if (LEDcolumnB==7)
                {
                  lc.setColumn(subject+1,2,B00000000);
                }
                if (LEDcolumnB==6)
                {
                  lc.setColumn(subject+1,1,B00000000);
                }
                if (LEDcolumnB==5)
                {
                  lc.setColumn(subject+1,0,B00000000);
                }
             }
          }
        }
        else
        {
          lc.setColumn(subject,LEDcolumnB+3,B00000000);
        }
        LEDcolumnB--;//only if subject has not exceeded the number of subjects but doesnt matter which column it is 
        delay(10);
      }
      else
      {
        LEDcolumnF=3;//if subject is -1, it skips the delay, and restarts it to the front program
        LEDback=0;
        subject=0;
      }
    }
    else//if circuit has exceeded the number of columns for a particular subject, it changes subject
    {
      LEDcolumnB=7;
      if (subject>-1)
      {
        subject--;
      }
    }
  }
}

