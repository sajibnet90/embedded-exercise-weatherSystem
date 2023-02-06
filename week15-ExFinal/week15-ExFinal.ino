#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);//bus speed
  pinMode(6,INPUT);//digital input
  pinMode(A2,INPUT);//analog input
  lcd.begin(16,2);
}

void loop() {
  const float pulseDuration = 100;   
  const float highPeriod = 60;
  const float lowPeriod = pulseDuration - highPeriod;
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  
  
  int analog_state= analogRead(A2);
  if(analog_state<200){
    Serial.println(analog_state);
  	lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Warning:");
    lcd.setCursor(3,1);
    lcd.print("Low Value");
  }else if(analog_state>1000){
    Serial.println(analog_state);
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Warning:");
    lcd.setCursor(0,1);
    lcd.print("Value Too High"); 
  delay(1000);
  }else{
  calculate(pulseDuration, highPeriod);
  delay(1000);
  }
}

void calculate(float pulseDuration, float highPeriod) {
  lcd.clear();
  
  int frequency = (100/pulseDuration);
  //Serial.println(frequency);
  lcd.setCursor(8,1);
  lcd.print("Fre:"+String(int(frequency))+ "Hz");

  int dutyCycle = (highPeriod / (float)pulseDuration) * 100;
  //Serial.println(dutyCycle);
  lcd.setCursor(0,1);
  lcd.print("dut:"+String(int(dutyCycle))+"%");
  
  int analog_state= analogRead(A2);
  lcd.setCursor(7,0);
  lcd.print("Ana.:"+String(int(analog_state)));
  //Serial.println(analog_state);
  //lcd.print(analog_state);
  
  
  int digi_state= digitalRead(6); //test digital signal D6
  lcd.setCursor(0,0);
  lcd.print("Dig.:");
  //Serial.println(digi_state);
  lcd.print(digi_state);

  
}

  
