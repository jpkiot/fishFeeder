#include <Servo.h>


int repetitions = 10; //number of turns the servo should make
long interval = 43200000; // interval between turns (12 hour)
unsigned long previousMillis = 43000000; // the last time the servo was turned

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  // check to see if it's time to turn the servo
  unsigned long currentMillis = millis();
  

  
  if(currentMillis - previousMillis >= interval)
  {
   // Serial.print("time passed: ");
   // Serial.print((currentMillis / 1000) / 60);
   // Serial.print(" minutes");
    previousMillis = currentMillis;
    
    for (int i=0; i <= repetitions; i += 1){
      
      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
      for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
    }
  }
}
