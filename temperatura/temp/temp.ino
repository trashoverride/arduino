/*
  LiquidCrystal Library - Hello World
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int LM35 = A0; // Pino Analogico onde vai ser ligado ao pino 2 do LM35
const int REFRESH_RATE = 2000;  //Tempo de atualização entre as leituras em ms
const float CELSIUS_BASE = 0.4887585532746823069403714565; //Base de conversão para Graus Celsius ((5/1023) * 100)
int rele = 8;
float temp;

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  pinMode(rele, OUTPUT);
  lcd.print("temperatura:");
}

void loop() {
  lcd.setCursor(0, 1);
  temp =   readTemperature();
  lcd.print(temp);
  if(temp > 50)
  {
      digitalWrite(rele, LOW);  
  }else{
      digitalWrite(rele, HIGH);  
  }
   
  delay(REFRESH_RATE);
}

float readTemperature(){
  return (analogRead(LM35) * CELSIUS_BASE); 
}
