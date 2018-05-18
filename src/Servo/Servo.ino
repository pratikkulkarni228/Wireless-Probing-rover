<<<<<<< HEAD:src/Servo/Servo.ino
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() 
{
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
//  Wire.begin();
}

void loop() 
{
//  Wire.beginTransmission(1);
  for (pos = 15; pos <= 165; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    Wire.write(pos)
    delay(30);                       // waits 15ms for the servo to reach the position

//    Wire.endTransmission();    
  }
  for (pos = 165; pos >= 15; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
}

=======
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

>>>>>>> abca5f2a0818c1e2ca4c23c225d9a837d216dfda:Codes/Servo/Sweep_final.ino
