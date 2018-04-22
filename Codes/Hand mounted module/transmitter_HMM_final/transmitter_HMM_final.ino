#include <VirtualWire.h>

const int xPin = A5; // analog pins
const int yPin = A3;
const int zPin = A4;
int foo = 0;
int bar = 0;
const char *msg="0";
void setup()
{
    Serial.begin(9600);	  // Debugging only
    Serial.println("setup");
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    // Initialise the IO and ISR
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec
    vw_set_tx_pin(11);
}

void loop()
{
    //--------------------Accelerometer---------------------------
  foo = (analogRead(xPin)-330);
  if(foo>30)
  {
      msg = "1"; //Right turn
      digitalWrite(3,HIGH);
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx(); // Wait until the whole message is gone
  }
  else if(foo < -20)
  {
      msg = "2"; //Left turn
      digitalWrite(4,HIGH);
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx(); // Wait until the whole message is gone
  }
  
  bar = (analogRead(zPin)-355);
  if(bar>20)
  {
      msg = "3"; //Backward
      digitalWrite(6,HIGH);
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx(); // Wait until the whole message is gone
  }
  else if(bar < -30)
  {
      msg = "4"; //Forward
      digitalWrite(5,HIGH);    
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx(); // Wait until the whole message is gone
  }
    
    
    
   // ---------------------Sending-----------------------------
    delay(500);
    digitalWrite(3,LOW);    
    digitalWrite(4,LOW);    
    digitalWrite(5,LOW);    
    digitalWrite(6,LOW);    

}
