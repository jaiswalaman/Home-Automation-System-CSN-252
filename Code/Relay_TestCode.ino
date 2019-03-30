#include <SoftwareSerial.h>
SoftwareSerial BTserial(3, 2); // rx-tx

int relay = 4;  

char c=0; // container

void setup()
{
  BTserial.begin(9600);
  
  pinMode (relay, OUTPUT);
  digitalWrite(relay, HIGH);

}

void loop() 
{

 
  
  if (BTserial.available())   // bluetooth code
    {
          c = BTserial.read();
          Serial.write(c);
          
         if (c == '1') // if container value is 1 then low
          {
            digitalWrite (relay,LOW);
          }
          
         if (c == '0') // if container value is 1 then high
          {
            digitalWrite (relay, HIGH);  
          }
          
     }
              
}
