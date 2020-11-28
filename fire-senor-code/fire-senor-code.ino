#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int firesensor=7;
int gassensor=6;

void setup() 
{
 lcd.begin(16,2); 
 pinMode(firesensor, INPUT);
 pinMode(gassensor, INPUT);
 Serial.begin(9600);
}

void loop() 
{
 int fire=digitalRead(firesensor);
 int gas=digitalRead(gassensor);
 int temp1=analogRead(A0);
 int temp=temp1/2;
if ((fire==HIGH)&&(gas==HIGH)&&(temp>=35))
{
 lcd.clear();
 lcd.print("fire occured");
 Serial.print('\r');
 Serial.print(fire);
 Serial.print('|');
 Serial.print(gas);
 Serial.print('|');
 Serial.print(temp);
 Serial.print('\n');
 delay(20);
}
else
{
 lcd.clear();
 lcd.print(" no fire ");
 Serial.print('\r');
 Serial.print(fire);
 Serial.print('|');
 Serial.print(gas);
 Serial.print('|');
 Serial.print(temp);
 Serial.print('\n');
 delay(20);
}

}
