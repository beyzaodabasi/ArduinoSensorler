#include <LiquidCrystal.h>

LiquidCrystal lcd {2,3,4,5,6,7};

int gazSensor=A0; 
int gazYogunlugu=0; //Değişken tanımı
int alarm=11; //Buzzer
int yesilLed=8;
int turuncuLed=9;
int kirmiziLed=10;

void setup()
{
  
  lcd.begin(16,2);
  pinMode(yesilLed, OUTPUT);
  pinMode(turuncuLed, OUTPUT);
  pinMode(kirmiziLed, OUTPUT);
  pinMode(alarm, OUTPUT);
  
}

void loop()
{ 
  
  gazYogunlugu=(analogRead(gazSensor));
  
  
  if (gazYogunlugu>180){
    
    digitalWrite(yesilLed, LOW);
    digitalWrite(turuncuLed, LOW);
    digitalWrite(kirmiziLed, HIGH);
    digitalWrite(alarm, HIGH);
    
    lcd.setCursor(0,0); //1. satır
    lcd.print("TEHLIKE!!  ");
    lcd.setCursor(0,1); //2. satır
    lcd.print(gazYogunlugu);
    
  }
  
  else if (gazYogunlugu>=120){
    
    digitalWrite(yesilLed, LOW);
    digitalWrite(turuncuLed, HIGH);
    digitalWrite(kirmiziLed, LOW);
    digitalWrite(alarm, HIGH);
    delay(200);
    
    lcd.setCursor(0,0); //1. satır
    lcd.print("DIKKAT!  ");
    lcd.setCursor(0,1); //2. satır
    lcd.print(gazYogunlugu);
    
  }
  
  else {
    
    digitalWrite(yesilLed, HIGH);
    digitalWrite(turuncuLed, LOW);
    digitalWrite(kirmiziLed, LOW);
    digitalWrite(alarm, LOW);
    delay(200);
    
    lcd.setCursor(0,0); //1. satır
    lcd.print("SORUN YOK ");
    lcd.setCursor(0,1); //2. satır
    lcd.print(gazYogunlugu);
  }

}
