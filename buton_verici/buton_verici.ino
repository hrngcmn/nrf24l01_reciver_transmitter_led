  
#include <SPI.h>                      
#include "RF24.h"   
int msg[1];
RF24 radio(8,10); 
const uint64_t pipe = 3535;

void setup() {
  Serial.begin(9600);
  pinMode(7,INPUT);
  radio.begin();
  radio.openWritingPipe(pipe);
  radio.stopListening();
  

}

void loop() {
  msg[0] = digitalRead(7);
  Serial.println(msg[0]);
  
  radio.write(msg,1);
  if(radio.available()  ) 
  {
    Serial.println("sinyal gönderiyor");
  }
 /* else
  {
    Serial.println("sinyal yok");
    delay(1000);
  } */

}
