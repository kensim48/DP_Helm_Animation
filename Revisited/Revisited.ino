int arrowFrame=0;


void setup() {
  int devices=lc.getDeviceCount();
  for(int address=0;address<devices;address++)
  {
    lc.shutdown(address,false);
    lc.setIntensity(address,3);
    lc.clearDisplay(address);
    attachInterrupt(0, add, HIGH);
  }
  randomSeed(analogRead(5));
}

void Arrows ()
{
  switch (arrowFrame){
    case 0:
      while(arrows<=4){
        lc.setRow(arrows,0,B00110000);
        lc.setRow(arrows,1,B01100000);
        lc.setRow(arrows,2,B11000000);
        lc.setRow(arrows,3,B10000001);
        lc.setRow(arrows,4,B10000001);
        lc.setRow(arrows,5,B11000000);
        lc.setRow(arrows,6,B01100000);
        lc.setRow(arrows,7,B00110000);
        arrows++;
      }
      break;
    case 1:
      while(arrows<=4)
    {
      lc.setRow(arrows,0,B01100000);
      lc.setRow(arrows,1,B11000000);
      lc.setRow(arrows,2,B10000001);
      lc.setRow(arrows,3,B00000011);
      lc.setRow(arrows,4,B00000011);
      lc.setRow(arrows,5,B10000001);
      lc.setRow(arrows,6,B11000000);
      lc.setRow(arrows,7,B01100000);
      arrows++;
    }
    arrows=0;
    delay(arrowt);
      while(arrows<=4)
    {
      lc.setRow(arrows,0,B11000000);
      lc.setRow(arrows,1,B10000001);
      lc.setRow(arrows,2,B00000011);
      lc.setRow(arrows,3,B00000110);
      lc.setRow(arrows,4,B00000110);
      lc.setRow(arrows,5,B00000011);
      lc.setRow(arrows,6,B10000001);
      lc.setRow(arrows,7,B11000000);
      arrows++;
    }
    arrows=0;
      delay(arrowt);
      while(arrows<=4)
    {
      lc.setRow(arrows,0,B10000001);
      lc.setRow(arrows,1,B00000011);
      lc.setRow(arrows,2,B00000110);
      lc.setRow(arrows,3,B00001100);
      lc.setRow(arrows,4,B00001100);
      lc.setRow(arrows,5,B00000110);
      lc.setRow(arrows,6,B00000011);
      lc.setRow(arrows,7,B10000001);
      arrows++;
    }
    arrows=0;
      delay(arrowt);
      while(arrows<=4)
    {
      lc.setRow(arrows,0,B00000011);
      lc.setRow(arrows,1,B00000110);
      lc.setRow(arrows,2,B00001100);
      lc.setRow(arrows,3,B00011000);
      lc.setRow(arrows,4,B00011000);
      lc.setRow(arrows,5,B00001100);
      lc.setRow(arrows,6,B00000110);
      lc.setRow(arrows,7,B00000011);
      arrows++;
    }
    arrows=0;
      delay(arrowt);
      while(arrows<=4)
    {
      lc.setRow(arrows,0,B00000110);
      lc.setRow(arrows,1,B00001100);
      lc.setRow(arrows,2,B00011000);
      lc.setRow(arrows,3,B00110000);
      lc.setRow(arrows,4,B00110000);
      lc.setRow(arrows,5,B00011000);
      lc.setRow(arrows,6,B00001100);
      lc.setRow(arrows,7,B00000110);
    
      arrows++;
    }
    arrows=0;
      delay(arrowt);
      while(arrows<=4)
    {
      lc.setRow(arrows,0,B00001100);
      lc.setRow(arrows,1,B00011000);
      lc.setRow(arrows,2,B00110000);
      lc.setRow(arrows,3,B01100000);
      lc.setRow(arrows,4,B01100000);
      lc.setRow(arrows,5,B00110000);
      lc.setRow(arrows,6,B00011000);
      lc.setRow(arrows,7,B00001100);
      arrows++;
    }
    arrows=0;
      delay(arrowt);
      while(arrows<=4)
    {
      lc.setRow(arrows,0,B00011000);
      lc.setRow(arrows,1,B00110000);
      lc.setRow(arrows,2,B01100000);
      lc.setRow(arrows,3,B11000000);
      lc.setRow(arrows,4,B11000000);
      lc.setRow(arrows,5,B01100000);
      lc.setRow(arrows,6,B00110000);
      lc.setRow(arrows,7,B00011000);
      arrows++;
  }
arrows=0;
delay(arrowt);
  }
}


void loop() {
  // put your main code here, to run repeatedly:

}
