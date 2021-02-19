# nRF24l01 Reciver - Transmitter 
2 ardiuno uno kullanarak yaptığım. nRF24l01 haberleştirmesi ile gerçekleştirdiğim. Vericiden butona basılarak, alıcıdan led yaktırıp söndürten kodarı içerir. 

## Önemli:
* nRF24L01 için adaptör kullanılmalıdır. 

![enter image description here](https://github.com/hrngcmn/nrf24l01_reciver_transmitter_led/blob/main/Screenshot_2.png?raw=true)
**M1= Arduino digital 12. pine
M2= Arduino digital 11. pine
Sck = Arduino digital 13. pine bağlanmalıdır.** 
CE, CSN yi digital portlardan herhangi birine bağlayabilirsiniz. 
ben CE'yi 8. pine, CSN'yi 10. pine bağladım arkadaşlar. 
Vcc = 5V veriniz.  Adaptör 5V girişi 3.3V çıkış gerilimine dönüştürmektedir.
GND = Arduino GND terminallerininden birine bağlayınız. Veya pilinizin GND sinede bağlayabilirsiniz. 


# Kodlarla alakalı notlar : 
## Verici kısmıyla alakalı

* Arduino digital 7. pininden buton okuması yaptım.

#include <SPI.h>      
#include "RF24.h"   
**Kütüphaneniz ekli değilse ekleyin.** 

Kütüphanelerini yüklemeniz gerekmektedir. Google üzerinden aratıp nrf24l01 kütüphanesini nr24 kütüphanesini indiriniz. Yoksa programınız hata verecektir. 

**RF24 radio(8,10)**; ile radionuzu oluşturunuz. CE, CSN pinleri tanıtılır. 


Verici kısmıyla alakalı: 

**const uint64_t pipe = 0xE8E8F0F0E1LL;** // haberleşmenin sağlanması için adres atanması gerekmektedir. Alıcı ve vericide bu adreslerin aynı olması gerekmektedir. Aynı olmazsa haberleşmeyi sağlayamazsınız. 

**radio.begin()**; // ile radyo başlatılır. 

**radio.openWritingPipe(pipe);** // vericinin yazacağı adres. 


## Alıcı kısmıyla alakalı:
* Arduino digital 6. pinden Led çıkışını yazdırıyorum. 

const uint64_t pipe = 0xE8E8F0F0E1LL; // vericinin adresi ile aynı. 

radio.begin(); // radyoyo başlat.

**radio.openReadingPipe(1, pipe);** // alcı olduğunu tanımlamış

**radio.startListening();** // Vericinin yazdığını dinelemeye başla. 

**if(radio.available())** // haberlesme aktif ise. 

## Kumanda Bağlantısı: 
![enter image description here](https://github.com/hrngcmn/nrf24l01_reciver_transmitter_led/blob/main/Screenshot_1.png?raw=true)

* Board üzerine kuracaksanız temassızlığa dikkat ediniz. nRF24l01 bu konularda hassastır.
* nrf24L01'e 5V verirseniz direk yakarsınız kartı dikkati olunuz. Adaptör kullanınız.
* Arduinonuzun Vin girişine  7 - 12 arası bi gerlim veriniz. İdeal olanı budur.

## Alıcı Bağlantısı

![enter image description here](https://github.com/hrngcmn/nrf24l01_reciver_transmitter_led/blob/main/Screenshot_3.png?raw=true)

* Tekerlek ve motor sizi şaşırtmasın arduinomu şase üzerine vidaladığım için çıkartmak istemedim bu nedenle onun üzerinde.
* Alıcımın enerjisini zaten direkt laptoptan alacak arduino harici bi voltaj kaynağı eklemedim.
*  Adaptörümün bağlantılarını vericideki gibi yaptım. Yeniden söyülüyorum CE, CSN istediğiniz yere takın ama diğerlerinin özel portları var. Yukarıda belirttiğim gibi yapınız. 

## Hatalar nerden kayanaklanabilir ? 
* Temazsızlık. Mesela bende board üzerine kurduğum için temassızlık sorunu çok oldu. bide nereden kaynaklı olduğu anlaşılmıyor. Adaptör girişlerindeki jumperler bastırdığımda haberleşme sağlayabiliyorum bazen. Aman dikkat edin derim. 
* Nrf24l01 Vin girişine 3.3V başka gerilim verme. 
* Nrf24l01 bağlantılarında M1, M2, SCK bağlantılarında bi yanlışlık yapma. 

Harun
















