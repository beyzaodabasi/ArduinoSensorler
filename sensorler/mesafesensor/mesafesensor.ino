#include <LiquidCrystal.h>

LiquidCrystal lcd {2,3,4,5,6,7};

int mesafe;  //Değişken tanımı
int sure;  //Değişken tanımı
int trigPin=10;
int echoPin=9;
int kirmiziLed=8;

void setup()
{
  
  lcd.begin(16,2);
  pinMode(trigPin, OUTPUT); //Ses dalgasını gönderen kısım 
  pinMode(echoPin, INPUT); //Ses dalgasını alan kısım
  pinMode(kirmiziLed, OUTPUT);
  
}

void loop()
{ 

  digitalWrite(trigPin, LOW);
  delay(200);
  
  digitalWrite(trigPin, HIGH); //Ses dalgası gönderilir
  delay(1000);
  
  digitalWrite(trigPin, LOW);
  sure=pulseIn(echoPin, HIGH); //Gelen darbe ölçülür sureye atanır
  
  mesafe=(sure/2) /29,1; //cm cinsine çevrilir
  
  lcd.setCursor(0,0); //1. satır
  lcd.print("Mesafe");
  lcd.setCursor(0,1); //2. satır
  lcd.print(mesafe);
  lcd.print(" cm");
  delay(100);
  
  
  if(mesafe<80){
    digitalWrite(kirmiziLed, HIGH);
    delay(300);
    digitalWrite(kirmiziLed, LOW);
    delay(300);
  }
  else{
    digitalWrite(kirmiziLed, LOW);
       
  }
  
}
