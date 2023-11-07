#include "mbed.h"
#include "LCD_DISCO_F469NI.h"
#define WAIT 1000ms
LCD_DISCO_F469NI lcd;

DigitalOut led(LED1);
DigitalIn button(PA_0);

Thread thread1;
Thread thread2;
Thread thread3;

void dioda() {
    while(true) {
        led = !led;
        ThisThread::sleep_for(WAIT/2);
    }
}

void displej() {
    while(true)
    {
      lcd.Clear(LCD_COLOR_BLUE);
      lcd.SetBackColor(LCD_COLOR_BLUE);
      lcd.SetTextColor(LCD_COLOR_WHITE);
      
      lcd.DisplayStringAt(0, LINE(4), (uint8_t *)"Slava! Vivat! Na zdravi!", CENTER_MODE);
      lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"At zije! Jupi!", CENTER_MODE);
      
      ThisThread::sleep_for(WAIT);
      lcd.SetTextColor(LCD_COLOR_BLUE);
      lcd.DisplayStringAt(0, LINE(4), (uint8_t *)"Slava! Vivat! Na zdravi!", CENTER_MODE);
      lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"At zije! Jupi!", CENTER_MODE);
      ThisThread::sleep_for(WAIT);      
    }
}

void  tlacitko(){
    while(true)
    {
        if(button) {
            lcd.Clear(LCD_COLOR_BLUE);
            lcd.SetBackColor(LCD_COLOR_BLUE);
            lcd.SetTextColor(LCD_COLOR_WHITE);
            
            lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"Daroval mi Frantik vranu", CENTER_MODE);
            lcd.DisplayStringAt(0, LINE(7), (uint8_t *)"Ja Mildovi kralika", CENTER_MODE);
            
            ThisThread::sleep_for(WAIT/2);
            lcd.SetTextColor(LCD_COLOR_BLUE);
            lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"Daroval mi Frantik vranu", CENTER_MODE);
            lcd.DisplayStringAt(0, LINE(7), (uint8_t *)"Ja Mildovi kralika", CENTER_MODE);
            ThisThread::sleep_for(WAIT/2); 
        }
           
    }
}

int main()
{    
    
    lcd.Clear(LCD_COLOR_BLUE);
    thread1.start(displej);
    thread2.start(dioda);
    thread3.start(tlacitko);
    
    
  
    
}

