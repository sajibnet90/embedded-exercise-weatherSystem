#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);//bus speed
  lcd.begin(16,2);
  
  pinMode(A5,INPUT);
  pinMode(7,OUTPUT);  
}

void loop() {
 
  double sensor_valueA5= analogRead(A5);
  // Convert the analog reading (which goes from 0 - 1023) 
  //to a voltage (0 - 5V)
  double current_voltage = sensor_valueA5 * (5.0 / 1023.0);
  lcd.setCursor(0,1);
  lcd.print(current_voltage);
  //scaled volatge (0-5) to the scale of (50-300)
  double new_value = 50 + (current_voltage *50);
  lcd.setCursor(0,0);
  lcd.print(new_value);
  
  // printing voltage at 0,3 and 5
  if(new_value>=50 && new_value<200 ){
    lcd.setCursor(7,1);
  //Serial.print(nvoltage);
  lcd.print(String(int(current_voltage=0)) +"V");
  }else if(new_value>=200 && new_value<300){
    lcd.setCursor(7,1);
  //Serial.print(nvoltage);
  lcd.print(String(int(current_voltage=3)) +"V");
  }else if(new_value>=300){
  	lcd.setCursor(7,1);
  //Serial.print(nvoltage);
  lcd.print(String(int(current_voltage=5)) +"V");
  }
 
}