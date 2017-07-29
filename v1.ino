// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            5

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16
#define NUMFRAME       47
// When we setup the NeoPixel library
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int x=0,y=0;
char in;


int led[NUMFRAME][NUMPIXELS]
= {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0},
{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1},
{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0},
{0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1},
{0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1},
{0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1},
{0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1},
{0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1},
{0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1},
{0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1},
{0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1},
{0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1},
{0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1},
{0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

void setup() {
  Serial.begin(115200);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  if(Serial.available()){
      in = Serial.read();
      if (in=='1'){
        led[x][y]=1;
        y++;
      }
      if (in=='2'){
        led[x][y]=0;
        y++;
      }
      if (in=='n'){
        x++;
        y=0;
      }
      if (in=='e'){
        x=0;
        y=0;
      }
      Serial.println(x);
      Serial.println(y);
   }
   else{
      for(int i=0;i<NUMFRAME;i++){
        delayMicroseconds(1205);
        for(int j=0;j<NUMPIXELS;j++){
          int intensity =  led[i][j] * 5;
          pixels.setPixelColor(j, pixels.Color(intensity,intensity,intensity)); // Moderately bright green color.
        }
        pixels.show(); // This sends the updated pixel color to the hardware.
      }
   }
}



