# nrf24l01_reciver_transmitter_led
2 ardionun uno kullanarak yaptığım. nRF24l01 haberleştirmesi ile gerçekleştirdiğim. Vericiden butona basılarak, alıcıdan led yaktırıp söndürten kodarı içerir.

Önemli:
* nRF24L01 için adaptör kullanılmalıdır. 

M1= Arduino digital 12. pine

M2= Arduino digital 11. pine

Sck = Arduino digital 13. pine bağlanmalıdır. 

CE, CSN yi digital portlardan herhangi birine bağlayabilirsiniz. 

ben CE'yi 9. pine, CSN'yi 10. pine bağladım arkadaşlar. 



Kodlarla alakalı notlar : 

#include <SPI.h>      

#include "RF24.h"   

kütüphanelerini yüklemeniz gerekmektedir. Google üzerinden aratıp nrf24l01 kütüphanesini nr24 kütüphanesini indiriniz. Yoksa programınız hata verecektir. 

RF24 radio(9,10); ile radionuzu oluşturunuz. CE, CSN pinleri tanıtılır. 


Verici kısmıyla alakalı: 

const uint64_t pipe = 0xE8E8F0F0E1LL; // haberleşmenin sağlanması için adres atanması gerekmektedir. Alıcı ve vericide bu adreslerin aynı olması gerekmektedir. Aynı olmazsa haberleşmeyi sağlayamazsınız. 

radio.begin(); // ile radyo başlatılır. 

radio.openWritingPipe(pipe); // vericinin yazacağı adres. 


Alıcı kısmıyla alakalı:

const uint64_t pipe = 0xE8E8F0F0E1LL; // vericinin adresi ile aynı. 

radio.begin(); // radyoyo başlat.

radio.openReadingPipe(1, pipe); // alcı olduğunu tanımlamış

radio.startListening(); // Vericinin yazdığını dinelemeye başla. 

if(radio.available()) // haberlesme aktif ise. 


















