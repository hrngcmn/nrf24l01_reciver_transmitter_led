#include <SPI.h>      
#include "RF24.h"   
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int msg[1];

void setup() {
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();

}

void loop() {
  if(radio.available())
  {
    radio.read(msg,1);
    Serial.println(msg[0]);
    delay(100);
    if(msg[0] == 1 ) 
    {
      digitalWrite(6,HIGH);
      delay(5000);
      digitalWrite(6, LOW);
      delay(1000);
    }
    else
    {
      digitalWrite(6,HIGH);
      delay(500);
      digitalWrite(6,LOW);
      delay(500);
      digitalWrite(6,HIGH);
      delay(500);
      digitalWrite(6,LOW);
      delay(500);
      digitalWrite(6,HIGH);
      delay(500);
      digitalWrite(6,LOW);
      delay(500);
    }

    
  }
  
}
