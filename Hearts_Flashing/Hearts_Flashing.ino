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
  //first heart
  lc.setRow(0,0,B00000110);
  lc.setRow(0,1,B00001001);
  lc.setRow(0,2,B00001000);
  lc.setRow(0,3,B00001000);
  lc.setRow(0,4,B00000100);
  lc.setRow(0,5,B00000010);
  lc.setRow(0,6,B00000001);
  lc.setRow(1,0,B01100000);
  lc.setRow(1,1,B10010000);
  lc.setRow(1,2,B00010000);
  lc.setRow(1,3,B00010000);
  lc.setRow(1,4,B00100000);
  lc.setRow(1,5,B01000000);
  lc.setRow(1,6,B10000000);

  //second heart
  lc.setRow(2,0,B01100110);
  lc.setRow(2,1,B10011001);
  lc.setRow(2,2,B10000001);
  lc.setRow(2,3,B10000001);
  lc.setRow(2,4,B01000010);
  lc.setRow(2,5,B00100100);
  lc.setRow(2,6,B00011000);
  //third heart
  lc.setRow(3,0,B00000110);
  lc.setRow(3,1,B00001001);
  lc.setRow(3,2,B00001000);
  lc.setRow(3,3,B00001000);
  lc.setRow(3,4,B00000100);
  lc.setRow(3,5,B00000010);
  lc.setRow(3,6,B00000001);
  lc.setRow(4,0,B01100000);
  lc.setRow(4,1,B10010000);
  lc.setRow(4,2,B00010000);
  lc.setRow(4,3,B00010000);
  lc.setRow(4,4,B00100000);
  lc.setRow(4,5,B01000000);
  lc.setRow(4,6,B10000000);
  delay (500);
  lc.setRow(0,0,B00000110);
  lc.setRow(0,1,B00001111);
  lc.setRow(0,2,B00001111);
  lc.setRow(0,3,B00001111);
  lc.setRow(0,4,B00000111);
  lc.setRow(0,5,B00000011);
  lc.setRow(0,6,B00000001);
  lc.setRow(1,0,B01100000);
  lc.setRow(1,1,B11110000);
  lc.setRow(1,2,B11110000);
  lc.setRow(1,3,B11110000);
  lc.setRow(1,4,B11100000);
  lc.setRow(1,5,B11000000);
  lc.setRow(1,6,B10000000);
  //second heart
  lc.setRow(2,0,B01100110);
  lc.setRow(2,1,B11111111);
  lc.setRow(2,2,B11111111);
  lc.setRow(2,3,B11111111);
  lc.setRow(2,4,B01111110);
  lc.setRow(2,5,B00111100);
  lc.setRow(2,6,B00011000);
  //third heart
  lc.setRow(3,0,B00000110);
  lc.setRow(3,1,B00001111);
  lc.setRow(3,2,B00001111);
  lc.setRow(3,3,B00001111);
  lc.setRow(3,4,B00000111);
  lc.setRow(3,5,B00000011);
  lc.setRow(3,6,B00000001);
  lc.setRow(4,0,B01100000);
  lc.setRow(4,1,B11110000);
  lc.setRow(4,2,B11110000);
  lc.setRow(4,3,B11110000);
  lc.setRow(4,4,B11100000);
  lc.setRow(4,5,B11000000);
  lc.setRow(4,6,B10000000);
  delay(500);
}
