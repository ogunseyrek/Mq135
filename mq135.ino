//Hilmi Ogün SEYREK
//ogunseyrek@gmail.com

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f,16,2);  

int olculendeger_mq135=A0;
int kirmiziPin = 9;
int yesilPin = 10;
int maviPin = 11;

void setup() 
{
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(kirmiziPin, OUTPUT);
  pinMode(yesilPin, OUTPUT);
  pinMode(maviPin, OUTPUT);
}

void loop()   
{
  olculendeger_mq135 = analogRead(A0);       
  Serial.print(olculendeger_mq135, DEC);
  Serial.println(" ppm -BILNET-");
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(olculendeger_mq135);
  lcd.setCursor(4,0);
  lcd.print("ppm -BILNET-");

//Normal hava
  if(olculendeger_mq135<=220)   //480
  {
  Serial.println("Hava Temiz");
  lcd.setCursor(0,1);
  lcd.print("Hava Temiz      ");
  RGB(0, 255, 255); //acik mavi
  delay(10000);
  }
  
//Karbondioksit 1. seviye
  if(olculendeger_mq135>=221 && olculendeger_mq135<=320) //580
  {
  Serial.println("CO2 1.Seviye");
  lcd.setCursor(0,1);
  lcd.print("CO2 1.Seviye     ");
  RGB(0, 255, 0); //yesil
  delay(10000);
  }
  
//Karbondioksit 2. seviye
  if(olculendeger_mq135>=321 && olculendeger_mq135<=420)  //679
  {
  Serial.println("CO2 2.Seviye");
  lcd.setCursor(0,1);
  lcd.print("CO2 2.Seviye     ");
  RGB(255, 255, 0); //sari
  delay(10000);
  }
  
//Karbondioksit 3. seviye
  if(olculendeger_mq135>=421 && olculendeger_mq135<=520) //780
  {
  Serial.println("CO2 3.Seviye");
  lcd.setCursor(0,1);
  lcd.print("CO2 3.Seviye     ");
  RGB(255, 0, 0); //kırmızı
  delay(10000);
  }
  
//Karbonmonoksit fazla
  if(olculendeger_mq135>=521 && olculendeger_mq135<=644) //844
  {
  Serial.println("Karbonmonoksit");
  lcd.setCursor(0,1);
  lcd.print("Karbonmonoksit ");
  RGB(80, 0, 80); //mor
  delay(10000);
  }
  
//Propan ve Butan fazla
  if(olculendeger_mq135>=645)  //985
  {
  Serial.println("Propan ve Butan");
  lcd.setCursor(0,1);
  lcd.print("Propan ve Butan ");
  RGB(255, 255, 255); //acik mavi
  delay(10000);
  }
  
}
void RGB(int kirmizi, int yesil, int mavi)
{
 analogWrite(kirmiziPin, 255 - kirmizi);
 analogWrite(yesilPin, 255 - yesil);
 analogWrite(maviPin, 255 - mavi);
}
