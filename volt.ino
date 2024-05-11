#include <LiquidCrystal.h>
const int rs = 9, en = 8, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
void setup() {
lcd.begin(16, 2);

pinMode(A0 , INPUT) ;
pinMode(A2 , INPUT) ;
pinMode(15, INPUT);
pinMode(6, INPUT);
pinMode(16 , INPUT) ;

}
int x = 0 ;
void loop() {
  if (digitalRead(16) == HIGH && x == 0 ){
    x = 1 ;
 delay(500);
  }
  else if (digitalRead(16) == HIGH && x == 1 ){
    x = 0 ;
    delay(500);
  }
  float V = analogRead(A0);
  float RV = (analogRead(A2)); 
  int selectR = digitalRead(15);
  int selectV = digitalRead(6);
if( x == 0) {
  lcd.clear();
  //voltmeter code
  lcd.setCursor(0,0);
  lcd.print("V=");
  if(selectV == HIGH){
      if( V < 518 && V >500){
    lcd.setCursor(2,0);
  lcd.print("0" );
    lcd.setCursor(5,1);
  lcd.print("-10 to 10");
   delay(555);
  }
    else{
  lcd.setCursor(2,0);
  lcd.print(((V-508.85)*3.96*5.03/1023) ,2);
    lcd.setCursor(5,1);
  lcd.print("-10 to 10");
   delay(555);
      }
  }
  if(selectV == LOW){
    if(V < 527.78 && V >517.57){
  lcd.setCursor(2,0);
    lcd.print("0");
        lcd.setCursor(5,1);
    lcd.print("-50 to 50");
   delay(555);
    }
    else{
  lcd.setCursor(2,0);
    lcd.print(((V-522.68)*19.91908*5.03/1023),2);
        lcd.setCursor(5,1);
    lcd.print("-50 to 50");
   delay(555);
    }}
}
else{
  //OHMMETER FIRST SCALE
  lcd.clear();
 if(selectR){
  lcd.setCursor(6,1);
  lcd.print("300 to 10k");
  if(RV>90 && RV<995){
  lcd.setCursor(3, 0);
  lcd.print((49250-(48.095750313*(RV)))/((RV)*5.03/1023));
  lcd.setCursor(0,0);
  lcd.print(" R=");
  delay(150);
  }
  else if(RV>=995) {
   lcd.setCursor(3, 0);
  lcd.print("0");
  lcd.setCursor(0,0);
  lcd.print(" R=");
  delay(500);
  }
  else {

  lcd.setCursor(3, 0);
  lcd.print("o.l");
  lcd.setCursor(0,0);
  lcd.print(" R=");
  delay(500);
  }
 }
 else if(!selectR){
  //OHMMETER SECOND SCALE
    lcd.clear();
  lcd.setCursor(7,1);
  lcd.print("10k to 1M");
 if(RV>92 && RV<935){
  lcd.setCursor(3, 0);
  lcd.print(((499000-(487.3046875*RV))/(RV*5.03/1023))/1000);
  lcd.setCursor(0,0);
  lcd.print(" R=");
  lcd.setCursor(15,0);
  lcd.print("k");
  delay(500); }
  else if(RV>=935) {
   lcd.setCursor(3, 0);
  lcd.print("0");
  lcd.setCursor(0,0);
  lcd.print(" R=");
  delay(500); }
  else {
  lcd.setCursor(3, 0);
  lcd.print("o.l");
  lcd.setCursor(0,0);
  lcd.print(" R=");
  delay(500); }
  }
}
delay(300);
}
