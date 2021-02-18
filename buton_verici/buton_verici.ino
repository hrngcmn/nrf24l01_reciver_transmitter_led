#include <SPI.h>                      
#include "RF24.h"   
int msg[1];
RF24 radio(9,10); 
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup() {
  pinMode(7,INPUT);
  radio.begin();
  radio.openWritingPipe(pipe);
  

}

void loop() {
  msg[0] = digitalRead(7);
  radio.write(msg,1);
  
  if(digitalRead(7) == 1 ) 
  {
    digitalWrite(6, HIGH);
    
  }
  else
  {
    digitalWrite(6, HIGH);
    delay(750);
    digitalWrite(6, LOW);
    delay(750);
  }


}
