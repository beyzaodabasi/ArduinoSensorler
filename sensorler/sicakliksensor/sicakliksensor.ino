#include <LiquidCrystal.h> //LCD kütüphanesi

LiquidCrystal lcd {2,3,4,5,6,7};

int sicaklik; //Değişken tanımı
int sicaklikPin=A0; //Sıcaklık sensörü
int maviLed=8;
int kirmiziLed=9;

void setup()
{
  
  lcd.begin(16,2); //16 sütun, 2 satır
  pinMode(maviLed, OUTPUT);
  pinMode(kirmiziLed, OUTPUT);
  
}

void loop()
{ 
  if(sicaklik<42){
    digitalWrite(maviLed, HIGH);
    digitalWrite(kirmiziLed, LOW);
    
  }
  else{
    digitalWrite(kirmiziLed, HIGH);
    digitalWrite(maviLed, LOW);
    
  }
    
  sicaklik=((analogRead(sicaklikPin)*4.88)-500)/10; 
  lcd.setCursor(0,0); //1. satır
  lcd.print("sicaklik: ");
  lcd.setCursor(0,1); //2. satır
  lcd.print(sicaklik);
  lcd.print(" C"); 
}
