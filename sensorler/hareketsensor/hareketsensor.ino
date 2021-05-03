#include <LiquidCrystal.h>

LiquidCrystal lcd {2,3,4,5,6,7};

int hareket=0; //Değişken tanımı
int hareketPin=9; //Hareket sensörü
int kirmiziLed=8;

void setup()
{
  
  lcd.begin(16,2);
  pinMode(hareketPin, INPUT);
  pinMode(kirmiziLed, OUTPUT);
  
}

void loop()
{ 
  hareket=digitalRead(hareketPin);
  delay(500);
  
  if(hareket==1){
    digitalWrite(kirmiziLed, HIGH);
    lcd.setCursor(0,0); //1. satır
    lcd.print("Hareket");
    lcd.setCursor(0,1); //2. satır
    lcd.print("Algilandi");
  }
  
  else{
    digitalWrite(kirmiziLed, LOW);
    lcd.setCursor(0,0);
    lcd.print("Hareket");
    lcd.setCursor(0,1);
    lcd.print("Algilanmadi");
       
  }
  
}
