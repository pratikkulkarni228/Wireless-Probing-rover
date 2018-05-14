#include <Servo.h>
Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() 
{
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() 
{
  for (pos = 15; pos <= 165; pos += 1) { // goes from 15 degrees to 165 degrees // in steps of 1 degree per iteration
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 30ms for the servo to reach the position

  }
  for (pos = 165; pos >= 15; pos -= 1) { // goes from 165 degrees to 15 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 30ms for the servo to reach the position
  }
}

