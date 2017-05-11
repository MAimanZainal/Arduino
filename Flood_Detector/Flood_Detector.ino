// defines pins numbers
#define trigPin 12 
#define echoPin 8
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

// defines variables
long duration;
int distance;
int buzzPin =  9;

//Ubah alamat 0x27 dengan alamat i2C kamu
LiquidCrystal_I2C lcd(0x27 ,2,1,0,4,5,6,7,3, POSITIVE);

void setup()
{
  pinMode(buzzPin, OUTPUT); // Sets the buzzPIN as an Output
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  lcd.begin (16,2); //LCD untuk ukuran 16x2
}
void loop()
{
  // read the input on analog pin 0:
  int RaindropSensor = analogRead(A0);
  digitalWrite(buzzPin, HIGH); 
  delayMicroseconds(50); 
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  //Calculating the distance
  distance= duration*0.034/2;
  lcd.clear();
  if (distance <=15)
  {
    lcd.setCursor(0,0);
    lcd.print("FLOOD: YES ");
    lcd.print(distance); // Prints the distance value from the sensor
    lcd.print("cm");
    digitalWrite(buzzPin, LOW);  
    delayMicroseconds(50);    
  }
  else 
  {
    lcd.setCursor(0,0);
    lcd.print("FLOOD: NO ");
    lcd.print(distance); // Prints the distance value from the sensor
    lcd.print("cm");
    digitalWrite(buzzPin, HIGH); 
    delayMicroseconds(50); 
  }
  
  if (RaindropSensor <=500)
  {
    lcd.setCursor(0,1);
    lcd.print("RAINING: YES ");
    digitalWrite(buzzPin, LOW);  
    delayMicroseconds(50);    
//  lcd.print(RaindropSensor); // Prints the distance value from the sensor
   }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("RAINING: NO ");
    digitalWrite(buzzPin, HIGH); 
    delayMicroseconds(50); 
//  lcd.print(RaindropSensor); // Prints the distance value from the sensor
  }
   delay(200);
   
}




