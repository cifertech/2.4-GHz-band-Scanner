#include <SPI.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4

#define CE  9

#define CHANNELS  64
int channel[CHANNELS];

int  line;
char grey[] = " .:-=+*aRW";

#define _NRF24_CONFIG      0x00
#define _NRF24_EN_AA       0x01
#define _NRF24_RF_CH       0x05
#define _NRF24_RF_SETUP    0x06
#define _NRF24_RPD         0x09


Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

byte count;
byte sensorArray[128];
byte drawHeight;

char filled = 'F'; 
char drawDirection = 'R'; 
char slope = 'W'; 


byte getRegister(byte r)
{
 byte c;
 
 PORTB &=~_BV(2);
 c = SPI.transfer(r&0x1F);
 c = SPI.transfer(0);  
 PORTB |= _BV(2);

 return(c);
}

void setRegister(byte r, byte v)
{
 PORTB &=~_BV(2);
 SPI.transfer((r&0x1F)|0x20);
 SPI.transfer(v);
 PORTB |= _BV(2);
}
 
void powerUp(void)
{
 setRegister(_NRF24_CONFIG,getRegister(_NRF24_CONFIG)|0x02);
 delayMicroseconds(130);
}

void powerDown(void)
{
 setRegister(_NRF24_CONFIG,getRegister(_NRF24_CONFIG)&~0x02);
}

void enable(void)
{
   PORTB |= _BV(1);
}

void disable(void)
{
   PORTB &=~_BV(1);
}

void setRX(void)
{
 setRegister(_NRF24_CONFIG,getRegister(_NRF24_CONFIG)|0x01);
 enable();

 delayMicroseconds(100);
}

void scanChannels(void)
{
 disable();
 for( int j=0 ; j<200  ; j++)
 {
   for( int i=0 ; i<CHANNELS ; i++)
   {
     setRegister(_NRF24_RF_CH,(128*i)/CHANNELS);
     
     setRX();
     
     delayMicroseconds(40);
     
     disable();
     
     if( getRegister(_NRF24_RPD)>0 )   channel[i]++;
   }
 }
}

void outputChannels(void)
{
 int norm = 0;
 
 for( int i=0 ; i<CHANNELS ; i++)
   if( channel[i]>norm ) norm = channel[i];
   
 Serial.print('|');
 for( int i=0 ; i<CHANNELS ; i++)
 {
   int pos;
   
   if( norm!=0 ) pos = (channel[i]*10)/norm;
   else          pos = 0;
   
   if( pos==0 && channel[i]>0 ) pos++;
   
   if( pos>9 ) pos = 9;
 
   Serial.print(grey[pos]);
   channel[i] = 0;
 }
 
 Serial.print("| ");
 Serial.println(norm);


  display.setCursor(90, 10);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print(norm);
  display.setCursor(90, 8);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.print("");


  display.drawLine(0, 0, 0, 32, WHITE);
  display.drawLine(80, 0, 80, 32, WHITE);

  for (count = 0; count < 40; count += 10)
  {
    display.drawLine(80, count, 75, count, WHITE);
    display.drawLine(0, count, 5, count, WHITE);
  }

  for (count = 10; count < 80; count += 10)
  {
    display.drawPixel(count, 0 , WHITE);
    display.drawPixel(count, 31 , WHITE);
  }

  
  drawHeight = map(norm, 0, 200, 0, 32 );
  sensorArray[0] = drawHeight;

  for (count = 1; count <= 80; count++ )
  {
    if (filled == 'D' || filled == 'd')
    {
      if (drawDirection == 'L' || drawDirection == 'l')
      {
        display.drawPixel(count, 32 - sensorArray[count - 1], WHITE);
      }
      else //else, draw dots from right to left
      {
        display.drawPixel(80 - count, 32 - sensorArray[count - 1], WHITE);
      }
    }


    

    else
    {
      if (drawDirection == 'L' || drawDirection == 'l')
      {
        if (slope == 'W' || slope == 'w')
        {
          display.drawLine(count, 32, count, 32 - sensorArray[count - 1], WHITE);
        }
        else
        {
          display.drawLine(count, 1, count, 32 - sensorArray[count - 1], WHITE);

        }
      }



      else
      {
        if (slope == 'W' || slope == 'w')
        {
          display.drawLine(80 - count, 32, 80 - count, 32 - sensorArray[count - 1], WHITE);
        }
        else
        {
          display.drawLine(80 - count, 1, 80 - count, 32 - sensorArray[count - 1], WHITE);
        }
      }
    }
  }

 // drawAxises();
  display.display(); 
  display.clearDisplay(); 

  for (count = 80; count >= 2; count--) 
  {
    sensorArray[count - 1] = sensorArray[count - 2];
  }
}

void printChannels(void)
{
 Serial.println(">      1 2  3 4  5  6 7 8  9 10 11 12 13  14                     <");
}

void setup()
{
 Serial.begin(57600);

 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  

 for (count = 0; count <= 128; count++) 
  {
    sensorArray[count] = 0;
  }
 
 Serial.println("Starting 2.4GHz Scanner ...");
 Serial.println();

 
 Serial.println("Channel Layout");
 printChannels();
 
 SPI.begin();
 SPI.setDataMode(SPI_MODE0);
 SPI.setClockDivider(SPI_CLOCK_DIV2);
 SPI.setBitOrder(MSBFIRST);
 
 pinMode(CE,OUTPUT);
 disable();
 
 powerUp();
 
 setRegister(_NRF24_EN_AA,0x0);
 

 setRegister(_NRF24_RF_SETUP,0x0F);
 
}

void loop()
{
  
 scanChannels();
 
 outputChannels();
 
 if( line++>12 )
 {
   printChannels();
   line = 0;
 }
}
