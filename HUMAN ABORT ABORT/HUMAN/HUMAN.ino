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
int leaderS=4;
int leaderC=7;

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
    lc.setIntensity(address,8);
    /* and clear the display */
    lc.clearDisplay(address);
  }
}

void loop()
{
  byte H[7]={B11111111,B11111111,B00011000,B00011000,B00011000,B11111111,B11111111};
  byte U[7]={B11111110,B11111111,B00000011,B00000011,B00000011,B11111111,B11111110};
  byte M[8]={B11111111,B11111111,B11100000,B00111000,B00111000,B11111111,B11111110};
  byte M[5]={B00011100,B00100010,B00100010,B00010010,B11111110};
  byte u[5]={B00111100,B00000010,B00000010,B00000100,B00111110};
  byte i[5]={B00000000,B00100010,B10111110,B00000010,B00000000};
  byte n[5]={B00111110,B00010000,B00100000,B00100000,B00011110};
  byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};
  
  lc.setColumn(leaderS,leaderC,H[0]);
  lc.setColumn(leaderS,2,H[1]);
  lc.setColumn(0,3,H[2]);
  lc.setColumn(0,4,H[3]);
  lc.setColumn(0,5,H[4]);
  lc.setColumn(0,6,H[5]);
  lc.setColumn(0,7,H[6]);
}
