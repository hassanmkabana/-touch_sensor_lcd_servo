/*Code by Hassan Mkabana
 at Gearbox Academy
 made on 24/2/2020
 */
#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <dht.h>
 #include <Servo.h>
 int servoPin = 9;
 int led = 8;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// constants won't change. They're used here to set pin numbers:
const int SENSOR_PIN = 7;       // the Arduino's input pin that connects to the sensor's SIGNAL pin 

// Variables will change:
int lastState = LOW;  // the previous state from the input pin
int currentState;     // the current reading from the input pin
 Servo servo1;

void setup() {
  lcd.begin(16, 2);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the Arduino's pin as aninput
  pinMode(SENSOR_PIN, INPUT);
  pinMode(led, OUTPUT);
  servo1.attach(servoPin);
  
}

void loop() {
  lcd.setCursor(0,1);
  
  // read the state of the the input pin:
  currentState = digitalRead(SENSOR_PIN);
  if(lastState == LOW && currentState == HIGH){
    //Serial.println("The sensor is touched");
    digitalWrite(servoPin, LOW);
    digitalWrite(led,HIGH);
    servo1.write(0);
    lcd.print("sensor:  touched");
    lcd.setCursor(0,0);
    lcd.print("Door: Open");
    delay(2000);
     }
  
    
  else if(lastState == HIGH && currentState == LOW){
    //Serial.println("The sensor is is released");
    digitalWrite(servoPin, HIGH);
    digitalWrite(led, LOW);
    servo1.write(90);
   lcd.print("sensor: released");
    lcd.setCursor(0,0);
    lcd.print("Door: Closed");
   }

  // save the the last state
  lastState = currentState;
   
}
