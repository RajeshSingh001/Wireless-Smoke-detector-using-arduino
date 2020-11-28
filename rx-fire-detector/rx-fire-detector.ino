#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup() 
{
Serial.begin(9600);
lcd.begin(16,2); 
}
void loop() 
{
 if (Serial.available()<1)  return;
  char R=Serial.read();
  if (R!='\r')                 return;
  int fire=Serial.parseInt();
  int gas=Serial.parseInt();
  int temp=Serial.parseInt();
  Serial.print('\r');
  Serial.print(fire);
  Serial.print('|');
  Serial.print(gas);
  Serial.print('|');
  Serial.print(temp);
  Serial.print('\n');
  if ((fire==1)&&(gas==1)&&(temp>=35))
    {
     lcd.clear();
     lcd.print("fire occured");
     delay(20);
    }
  else
    {
     lcd.clear();
     lcd.print(" no fire ");
     delay(20);
    }
 }
