  #include <VirtualWire.h>

int recvdist;
char container[5];
void setup()
{
    Serial.begin(9600);
    vw_set_ptt_inverted(true);
    vw_setup(2000);
    vw_set_rx_pin(2);
    vw_rx_start();
}

void loop()
{
    
//        Serial.println(recvdist);  
        
        for(int i=15;i<=165;i++)
        {  
          delay(30);
//            myServo.write(i);


            uint8_t buf[VW_MAX_MESSAGE_LEN];
            uint8_t buflen = VW_MAX_MESSAGE_LEN;    
            if(vw_get_message(buf,&buflen))
            {
                int i;
        //        Serial.print("GOT: ");
                for(i = 0;i < buflen;i++)
                {
                    container[i]= char (buf[i]);
                }
                container[buflen]='\0';
                recvdist = atoi(container);

            }
//            recvdist = getdist();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
            
            Serial.print(i); // Sends the current degree into the Serial Port
            Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
            
            Serial.print(recvdist); // Sends the distance value into the Serial Port
            Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
            
        } 
        for(int i=165;i>15;i--)
        {  
//            myServo.write(i);
            delay(30);

            uint8_t buf[VW_MAX_MESSAGE_LEN];
            uint8_t buflen = VW_MAX_MESSAGE_LEN;    
            if(vw_get_message(buf,&buflen))
            {
                int i;
        //        Serial.print("GOT: ");
                for(i = 0;i < buflen;i++)
                {
                    container[i]= char (buf[i]);
                }
                container[buflen]='\0';
                recvdist = atoi(container);

            }
//            recvdist = getdist();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
            
            Serial.print(i); // Sends the current degree into the Serial Port
            Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
            
            Serial.print(recvdist); // Sends the distance value into the Serial Port
            Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
            
        } 
    
    delay(1000);
  
}
//int getdist()
//{
//    uint8_t buf[VW_MAX_MESSAGE_LEN];
//    uint8_t buflen = VW_MAX_MESSAGE_LEN;    
//    if(vw_get_message(buf,&buflen))
//    {
//        int i;
////        Serial.print("GOT: ");
//        for(i = 0;i < buflen;i++)
//        {
//            container[i]= char (buf[i]);
//        }
//        container[buflen]='\0';
//        recvdist = atoi(container);
////        Serial.println(recvdist);
//        return recvdist;
//    }
//}
