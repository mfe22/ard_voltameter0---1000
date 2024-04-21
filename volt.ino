#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
void setup() {
lcd.begin(16, 2);

pinMode(A0 , INPUT) ;
pinMode(A1 , INPUT) ;
pinMode(A2 , INPUT) ;
pinMode(0,INPUT);
pinMode(7,OUTPUT);

}


void loop() {

  float s1 = analogRead(A0);
  float s2 = analogRead(A1);
  float s3 = analogRead(A2); 
  if(digitalRead(0) == 1){
  digitalWrite(7, HIGH);
  }
  else{
    digitalWrite(7,LOW);
  }
  if(s1 < 10 && abs(s2)<20.5 && abs(s3) <20.5){
  lcd.setCursor(0,0);
  lcd.print("voltmeter         ");
  lcd.setCursor(1,1);
  lcd.print("                           ");
}
if(s1 > 0 && abs(s2)<20.5 && abs(s3) <20.5){
  lcd.setCursor(0,0);
  lcd.print("volt =      ");
  lcd.setCursor(1 , 1 );
  lcd.print((s1*10/1024)+.05);
}
if(s2> 0 && abs(s1)<20.5 && abs(s3) <20.5){
  lcd.setCursor(0,0);
  lcd.print("volt =          ");
  lcd.setCursor(1 , 1 );
  lcd.print(s2*20*5/1024);
}
if(s3 > 0 && abs(s2)<20.5 && abs(s1) <20.5){
  lcd.setCursor(0,0);
  lcd.print("volt =          ");
  lcd.setCursor(1 , 1 );
  lcd.print(s3*200*5/1024);
}

}
