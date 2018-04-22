#include <VirtualWire.h> 

#define trigPin 6
#define echoPin 4

#define motor_1_a 34
#define motor_1_b 36

#define motor_2_a 38
#define motor_2_b 40

char distarr[5];

char c;
String str = " ";
int Val;

void setup()
{
    Serial.begin(9600);	// Debugging only
    Serial.println("setup");

    // Initialise the IO and ISR
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec
    vw_set_rx_pin(2);
    vw_rx_start();       // Start the receiver PLL running

    vw_set_tx_pin(11);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    pinMode(motor_1_a,OUTPUT);
    pinMode(motor_1_b,OUTPUT);
    
    pinMode(motor_2_a,OUTPUT);
    pinMode(motor_2_b,OUTPUT);
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
	      int i;

        digitalWrite(13, true); // Flash a light to show received good message
      	
      	Serial.print("Got: ");
      	for (i = 0; i < buflen; i++)
      	{
      	    Serial.print(buf[i], HEX);
        // Remove the print statements after testing
            if (isDigit(c=(char)(*(buf+i))))
              str = c;
      
            Val =str.toInt();
//            Serial.println("below is");
//            Serial.println("goo: ");
//            Serial.print(Val);
            
      	}//end of for
//       Serial.println("goo2: ");
//        Serial.println(Val);    // Remove AT
        if(Val == 1)
        {
            Serial.println("rt");
        digitalWrite(motor_1_a,HIGH);
        digitalWrite(motor_1_b,LOW);
        digitalWrite(motor_2_a,LOW);
        digitalWrite(motor_2_b,HIGH);
            delay(500);     
        }//end of if1
        if(Val == 2)
        {
            Serial.println("lt");
        digitalWrite(motor_1_a,LOW);
        digitalWrite(motor_1_b,HIGH);
        digitalWrite(motor_2_a,HIGH);
        digitalWrite(motor_2_b,LOW);
            delay(500);       
        }//end of if2
        if(Val == 3)
        {
            Serial.println("bk");
        digitalWrite(motor_1_a,LOW);
        digitalWrite(motor_1_b,HIGH);
        digitalWrite(motor_2_a,LOW);
        digitalWrite(motor_2_b,HIGH);
            delay(1000);       
        }//end of if3
        if(Val == 4)
        {
            Serial.println("fr");
        digitalWrite(motor_1_a,HIGH);
        digitalWrite(motor_1_b,LOW);
        digitalWrite(motor_2_a,HIGH);
        digitalWrite(motor_2_b,LOW);
            delay(1000);       
        }//end of if4
        
        digitalWrite(motor_1_a,LOW);
        digitalWrite(motor_1_b,LOW);
        digitalWrite(motor_2_a,LOW);
        digitalWrite(motor_2_b,LOW);    
      
	      Serial.println("");
        digitalWrite(13, false);
}//end of if - message recieved
    //-----------------Ultrasonic sensor---------------------------
    long duration, distance;

    digitalWrite(trigPin, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    //  Serial.println(distance);
    if (distance >= 600 || distance <= 0)
    {
        Serial.println("Out of range");
    }
    else 
    {
      Serial.print(distance);
      Serial.println(" cm");
        itoa(distance,distarr,10);
        vw_send((uint8_t *)distarr,strlen(distarr));
        vw_wait_tx();
    }
    delay(400);
}//end of loop
