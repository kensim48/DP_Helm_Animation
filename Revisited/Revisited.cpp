#include <Arduino.h>
#include "LedControl.h"

LedControl lc = LedControl(12,11,10,5);
int animNumber = 0;
int frameDelay = 4;
//
int arrowFrame = 0;
int arrowScreen = 0;
//
int blinkingEyesFrame = 0;
//
int heartBeatFrame = 0;
//
int cylonScannerFrame = 0;
int cylonOn;
int cylonOff;
int sCylonOn;
int sCylonOff;
//
int allLightsOnFrame = 0;
int sLightsOn;
int lightsOn;
//
int heartsFlashingFrame = 0;
//
int heartsFlashingFrame = 0;
//
int helloFrame = 0;
int helloOff = 0;
int sHelloOff = 0;
//
int lazerEyeFrame = 0;
int lazerEyeOn;
int lazerEyeOff;
int sLazerEyeOn;
int sLazerEyeOff;
//
int musicBarFrame = 0;
int musicR[32]={7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7};
int musicC[32]={1,2,3,4,6,7,0,1,3,4,5,6,0,1,2,3,5,6,7,0,2,3,4,5,7,0,1,2,4,5,6,7};
int musicS[32]={0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,4,4};
int musicbarnum=0;
int randmusic;
int musicBarcounter=0;


void setup() {
  int devices=lc.getDeviceCount();
  for(int address=0;address<devices;address++)
  {
    lc.shutdown(address,false);
    lc.setIntensity(address,3);
    lc.clearDisplay(address);
    //attachInterrupt(0, add, HIGH);
  }
  randomSeed(analogRead(5));
}

void Arrow()
{
  switch (arrowFrame){
    case 0:
      while(arrowScreen<=4) {
        lc.setRow(arrowScreen,0,B00110000);
        lc.setRow(arrowScreen,1,B01100000);
        lc.setRow(arrowScreen,2,B11000000);
        lc.setRow(arrowScreen,3,B10000001);
        lc.setRow(arrowScreen,4,B10000001);
        lc.setRow(arrowScreen,5,B11000000);
        lc.setRow(arrowScreen,6,B01100000);
        lc.setRow(arrowScreen,7,B00110000);
        arrowScreen++;
    }
      break;
    case 1:
      while(arrowScreen<=4) {
        lc.setRow(arrowScreen,0,B01100000);
        lc.setRow(arrowScreen,1,B11000000);
        lc.setRow(arrowScreen,2,B10000001);
        lc.setRow(arrowScreen,3,B00000011);
        lc.setRow(arrowScreen,4,B00000011);
        lc.setRow(arrowScreen,5,B10000001);
        lc.setRow(arrowScreen,6,B11000000);
        lc.setRow(arrowScreen,7,B01100000);
        arrowScreen++;
    }
      break;
    case 3:
      while(arrowScreen<=4) {
        lc.setRow(arrowScreen,0,B11000000);
        lc.setRow(arrowScreen,1,B10000001);
        lc.setRow(arrowScreen,2,B00000011);
        lc.setRow(arrowScreen,3,B00000110);
        lc.setRow(arrowScreen,4,B00000110);
        lc.setRow(arrowScreen,5,B00000011);
        lc.setRow(arrowScreen,6,B10000001);
        lc.setRow(arrowScreen,7,B11000000);
        arrowScreen++;
    }
      break;
    case 4:    
      while(arrowScreen<=4) {
        lc.setRow(arrowScreen,0,B10000001);
        lc.setRow(arrowScreen,1,B00000011);
        lc.setRow(arrowScreen,2,B00000110);
        lc.setRow(arrowScreen,3,B00001100);
        lc.setRow(arrowScreen,4,B00001100);
        lc.setRow(arrowScreen,5,B00000110);
        lc.setRow(arrowScreen,6,B00000011);
        lc.setRow(arrowScreen,7,B10000001);
        arrowScreen++;
    }
      break;
    case 5:
      while(arrowScreen<=4) {
        lc.setRow(arrowScreen,0,B00000011);
        lc.setRow(arrowScreen,1,B00000110);
        lc.setRow(arrowScreen,2,B00001100);
        lc.setRow(arrowScreen,3,B00011000);
        lc.setRow(arrowScreen,4,B00011000);
        lc.setRow(arrowScreen,5,B00001100);
        lc.setRow(arrowScreen,6,B00000110);
        lc.setRow(arrowScreen,7,B00000011);
        arrowScreen++;
    }
      break;
    case 6:
      while(arrowScreen<=4) {
        lc.setRow(arrowScreen,0,B00000110);
        lc.setRow(arrowScreen,1,B00001100);
        lc.setRow(arrowScreen,2,B00011000);
        lc.setRow(arrowScreen,3,B00110000);
        lc.setRow(arrowScreen,4,B00110000);
        lc.setRow(arrowScreen,5,B00011000);
        lc.setRow(arrowScreen,6,B00001100);
        lc.setRow(arrowScreen,7,B00000110);
        arrowScreen++;
    }
      break;
    case 7:
      while(arrowScreen<=4) {
        lc.setRow(arrowScreen,0,B00001100);
        lc.setRow(arrowScreen,1,B00011000);
        lc.setRow(arrowScreen,2,B00110000);
        lc.setRow(arrowScreen,3,B01100000);
        lc.setRow(arrowScreen,4,B01100000);
        lc.setRow(arrowScreen,5,B00110000);
        lc.setRow(arrowScreen,6,B00011000);
        lc.setRow(arrowScreen,7,B00001100);
        arrowScreen++;
    }
      break;
    case 8:
      while(arrowScreen<=4) {
        lc.setRow(arrowScreen,0,B00011000);
        lc.setRow(arrowScreen,1,B00110000);
        lc.setRow(arrowScreen,2,B01100000);
        lc.setRow(arrowScreen,3,B11000000);
        lc.setRow(arrowScreen,4,B11000000);
        lc.setRow(arrowScreen,5,B01100000);
        lc.setRow(arrowScreen,6,B00110000);
        lc.setRow(arrowScreen,7,B00011000);
        arrowScreen++;
    }
      break;
  }
  arrowFrame = (arrowFrame + 1) % 9;
}

void BlinkingEyes()
{ 
    switch(blinkingEyesFrame){
        case 0:
            lc.setRow(1,1,B00011100);
            lc.setRow(1,2,B00111110);
            lc.setRow(1,3,B01100011);
            lc.setRow(1,4,B01100011);
            lc.setRow(1,5,B00111110);
            lc.setRow(1,6,B00011100);
            //
            lc.setRow(3,1,B00111000);
            lc.setRow(3,2,B01111100);
            lc.setRow(3,3,B11000110);
            lc.setRow(3,4,B11000110);
            lc.setRow(3,5,B01111100);
            lc.setRow(3,6,B00111000);
            break;
        case 1:
            lc.setRow(1,1,B00000000);
            lc.setRow(1,2,B0000000);
            lc.setRow(1,3,B01111111);
            lc.setRow(1,4,B01111111);
            lc.setRow(1,5,B0000000);
            lc.setRow(1,6,B00000000);
            //
            lc.setRow(3,1,B00000000);
            lc.setRow(3,2,B0000000);
            lc.setRow(3,3,B11111110);
            lc.setRow(3,4,B11111110);
            lc.setRow(3,5,B0000000);
            lc.setRow(3,6,B00000000);
            break;
    }
    blinkingEyesFrame = (blinkingEyesFrame + 1) % 3;
}

void HeartBeat()
{
    if (heartBeatFrame<=39){
        switch(heartBeatFrame){
            case 0:
                lc.setColumn(0,0,B00001000);
                break;
            case 1:
                lc.setColumn(0,1,B00001000);
                break;
            case 2:
                lc.setColumn(0,2,B00001000);
                break;
            case 3:
                lc.setColumn(0,3,B00001000);
                break;
            case 4:
                lc.setColumn(0,4,B00001000);
                break;
            case 5:
                lc.setColumn(0,5,B00001000);
                break;
            case 6:
                lc.setColumn(0,6,B00001000);
                break;
            case 7:
                lc.setColumn(0,7,B00001000);
                break;
            case 8:
                lc.setColumn(1,0,B00001000);
                break;
            case 9:
                lc.setColumn(1,1,B00001000);
                break;
            case 10:
                lc.setColumn(1,2,B00001000);
                break;
            case 11:
                lc.setColumn(1,3,B00001000);
                break;
            case 12:
                lc.setColumn(1,4,B00001000);
                break;
            case 13:
                lc.setColumn(1,5,B00001100);
                break;
            case 14:
                lc.setColumn(1,6,B00000110);
                break;
            case 15:
                lc.setColumn(1,7,B00000011);
                break;
            case 16:
                lc.setColumn(2,0,B00000011);
                break;
            case 17:
                lc.setColumn(2,1,B00000110);
                break;
            case 18:
                lc.setColumn(2,2,B00001100);
                break;
            case 19:
                lc.setColumn(2,3,B00011000);
                break;
            case 20:
                lc.setColumn(2,4,B00110000);
                break;
            case 21:
                lc.setColumn(2,5,B01100000);
                break;
            case 22:
                lc.setColumn(2,6,B11000000);
                break;
            case 23:
                lc.setColumn(2,7,B11000000);
                break;
            case 24:
                lc.setColumn(3,0,B01100000);
                break;
            case 25:
                lc.setColumn(3,1,B00110000);
                break;
            case 26:
                lc.setColumn(3,2,B00010000);
                break;
            case 27:
                lc.setColumn(3,3,B00010000);
                break;
            case 28:
                lc.setColumn(3,4,B00010000);
                break;
            case 29:
                lc.setColumn(3,5,B00010000);
                break;
            case 30:
                lc.setColumn(3,6,B00010000);
                break;
            case 31:
                lc.setColumn(3,7,B00010000);
                break;
            case 32:
                lc.setColumn(4,0,B00010000);
                break;
            case 33:
                lc.setColumn(4,1,B00010000);
                break;
            case 34:
                lc.setColumn(4,2,B00010000);
                break;
            case 35:
                lc.setColumn(4,3,B00010000);
                break;
            case 36:
                lc.setColumn(4,4,B00010000);
                break;
            case 37:
                lc.setColumn(4,5,B00010000);
                break;
            case 38:
                lc.setColumn(4,6,B00010000);
                break;
            case 39:
                lc.setColumn(4,7,B00010000);
                break;

        }
    }
    else{
        int beatC = (heartBeatFrame - 40) % 8;
        int beatS = (heartBeatFrame - 40) / 8;
        lc.setColumn(beatS,beatC,B00000000);
    }
    //48=1,0
    //56=2,0
    //64=3,0
    //72=4,0
    //80=5,0
    heartBeatFrame = (heartBeatFrame + 1) % 80;
}

void CylonScanner()
{
    if (cylonScannerFrame==0){
        lc.setColumn(0,0,B11111111);
        lc.setColumn(0,1,B11111111);
        lc.setColumn(0,2,B11111111);
    } else if (cylonScannerFrame < 38){
        cylonOn = (cylonScannerFrame + 2) % 8;
        sCylonOn = (cylonScannerFrame + 2) / 8;
        cylonOff = (cylonScannerFrame) % 8;
        sCylonOff = (cylonScannerFrame) / 8;
        lc.setColumn(sCylonOn,cylonOn,B11111111);
        lc.setColumn(sCylonOff,cylonOff,B00000000);
    } else {
        cylonOn = (36-(cylonScannerFrame-39)) % 8;
        sCylonOn = (36-(cylonScannerFrame-39)) / 8;
        cylonOff = (39-(cylonScannerFrame-39)) % 8;
        sCylonOff = (39-(cylonScannerFrame-39)) / 8;
        lc.setColumn(sCylonOn,cylonOn,B11111111);
        lc.setColumn(sCylonOff,cylonOff,B00000000);
    }
    cylonScannerFrame = (cylonScannerFrame + 1) % 76;
}

void AllLightsOn()
{
    if (allLightsOnFrame < 40){
        lightsOn = (allLightsOnFrame) % 8;
        sLightsOn = (allLightsOnFrame) / 8;
        lc.setColumn(sLightsOn,lightsOn,B11111111);
    } else if (allLightsOnFrame < 80) {
        lightsOn = (39-(allLightsOnFrame-40)) % 8;
        sLightsOn = (39-(allLightsOnFrame-40)) / 8;
        lc.setColumn(sLightsOn,lightsOn,0);
    } else if (allLightsOnFrame < 120) {
        lightsOn = (39-(allLightsOnFrame-80)) % 8;
        sLightsOn = (39-(allLightsOnFrame-80)) / 8;
        lc.setColumn(sLightsOn,lightsOn,B11111111);
    } else {
        lightsOn = (allLightsOnFrame-120) % 8;
        sLightsOn = (allLightsOnFrame-120) / 8;
        lc.setColumn(sLightsOn,lightsOn,0);
    }
    allLightsOnFrame = (allLightsOnFrame + 1) % 160;
    // need to add pause in between each on/off cycle
}

void HeartsFlashing()
{
    switch (heartsFlashingFrame){
        case 0:
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
            break;
        case 1:
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
            break;
    }
    heartsFlashingFrame = (heartsFlashingFrame + 1) % 2;
}

void Hello()
{
    switch (helloFrame){
        case 0:
            lc.setRow(1,7,B10001001);
            lc.setRow(2,7,B11101110);
            lc.setRow(3,7,B11100111);
            break;
        case 1:
            lc.setRow(1,6,B10001010);
            lc.setRow(2,6,B00000100);
            lc.setRow(3,6,B01001000);
            lc.setRow(4,6,B10000000);
            break;
        case 2:
            lc.setRow(1,5,B10001011);
            lc.setRow(2,5,B11000100);
            lc.setRow(3,5,B01001000);
            lc.setRow(4,5,B10000000);
            break;
        case 3:
            lc.setRow(1,4,B11111010);
            lc.setRow(2,4,B00100100);
            lc.setRow(3,4,B01001000);
            lc.setRow(4,4,B10000000);
            break;
        case 4:
            lc.setRow(1,3,B10001001);
            lc.setRow(2,3,B11000100);
            lc.setRow(3,3,B01000111);
            break;
        case 5:
            lc.setRow(1,2,B10001000);
            lc.setRow(2,2,B00000100);
            lc.setRow(3,2,B01000000);
            break;
        case 6:
            lc.setRow(1,1,B10001000);
            lc.setRow(2,1,B00001100);
            lc.setRow(3,1,B11000000);
            break;
        case 7:
            while (sHelloOff<=4) {
                while (helloOff<=7) {
                    lc.setRow(sHelloOff,helloOff,B00000000);
                    helloOff++;
                }
                helloOff=0;
                sHelloOff++;
            }
            sHelloOff=0;
            helloOff=0;
            break;
    }
    helloFrame = (helloFrame + 1)  % 8;
}

void LazerEye()
{
    if (lazerEyeFrame==0){
        lc.setColumn(0,0,B00011000);
        lc.setColumn(0,1,B00011000);
    } else if (lazerEyeFrame < 39){
        lazerEyeOn = (lazerEyeFrame + 1) % 8;
        sLazerEyeOn = (lazerEyeFrame + 1) / 8;
        lazerEyeOff = (lazerEyeFrame) % 8;
        sLazerEyeOff = (lazerEyeFrame) / 8;
        lc.setColumn(sLazerEyeOn,lazerEyeOn,B00011000);
        lc.setColumn(sLazerEyeOff,lazerEyeOff,B00000000);
    } else {
        lazerEyeOn = (38-(lazerEyeFrame-40)) % 8;
        sLazerEyeOn = (38-(lazerEyeFrame-40)) / 8;
        lazerEyeOff = (40-(lazerEyeFrame-40)) % 8;
        sLazerEyeOff = (40-(lazerEyeFrame-40)) / 8;
        lc.setColumn(sLazerEyeOn,lazerEyeOn,B00011000);
        lc.setColumn(sLazerEyeOff,lazerEyeOff,B00000000);
    }
    lazerEyeFrame = (lazerEyeFrame + 1) % 76;
}

void MusicBars()
{
    if (musicBarFrame == 0) {
        while (musicbarnum<32) {
            musicR[musicbarnum]=7;
            musicbarnum++;
        }
        musicBarFrame++;
        musicbarnum=0;
    }
    randmusic=random(0,4);
    while (musicBarcounter<=3) {
        lc.setLed(musicS[musicbarnum],musicR[musicbarnum],musicC[musicbarnum],true);
        lc.setLed(musicS[musicbarnum],musicR[musicbarnum]-1,musicC[musicbarnum],false);
        if (randmusic==1) {
            musicR[musicbarnum]++;
        }
        else if (randmusic==2) {
            musicR[musicbarnum]--;
        }
        if (musicR[musicbarnum]==8) {
            musicR[musicbarnum]=7;
        }
        if (musicR[musicbarnum]==-1) {
            musicR[musicbarnum]=0;
        }
        musicbarnum++;
        musicBarcounter++;
    }
    musicBarcounter=0;
    if (musicbarnum>31) {
        musicbarnum=0;
        musicBarcounter=0;
        delay(10);//todo: find out wtf is this for
    }
}

void loop() {
    switch(animNumber){
        case 0:
          Arrow();
          break;
    }
  delay(frameDelay);

  //reset all frame counters upon IRQ
  //Maybe can use one frame counter for all anims??
}
