// include the library code:
#include <LiquidCrystal.h>

//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  LiquidCrystal lcd(13, 12, 11, 10,  9,  8);

//Define the Pin Numbers
const int SENSOR_PIN = 2;
const int SPEAKER_PIN = 5;
const int RLED_PIN = 7;
const int GLED_PIN = 6;
 
void setup ()  
{   
  pinMode (SENSOR_PIN, INPUT); // Set the Sensor pin as INPUT  
  pinMode(SPEAKER_PIN, OUTPUT);  // Set the Red LED pin as OUTPUT 
  pinMode(RLED_PIN, OUTPUT);  // Set the Red LED pin as OUTPUT 
  pinMode(GLED_PIN, OUTPUT);  // Set the Green LED pin as OUTPUT 

  lcd.begin(20, 4); // set up the LCD's number of columns and rows:
  lcd.setCursor(0,0); // set the cursor position:
  lcd.print("Arduino Based");
  lcd.setCursor(0,1);
  lcd.print(" RAIN DETECTOR  ");
}  
void loop ()  
{
  int Sensor_Val = digitalRead(SENSOR_PIN);  //get reading from Sensor
  
  if (Sensor_Val == HIGH) //If Sensor Detected the Rain
  {
    digitalWrite(RLED_PIN, HIGH);
    digitalWrite(SPEAKER_PIN, HIGH);
    digitalWrite(GLED_PIN, LOW);
    
    lcd.setCursor(0, 3);
    lcd.print("   Rain Detected             ");
    delay(100);
    lcd.setCursor(0, 3);
    lcd.print("   Rain Detected.             ");
    delay(100);
    lcd.setCursor(0, 3);
    lcd.print("   Rain Detected..             ");
    delay(100);
    lcd.setCursor(0, 3);
    lcd.print("   Rain Detected...             ");
    delay(100);
  }
  else
  {
    lcd.setCursor(0, 3);
    lcd.print("      NO RAIN             ");
    digitalWrite(RLED_PIN, LOW);
    digitalWrite(SPEAKER_PIN, LOW);
    digitalWrite(GLED_PIN, HIGH);
  }
}
