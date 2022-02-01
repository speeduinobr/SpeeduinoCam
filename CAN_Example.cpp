


#include <SpeedData.h>

//#define Uno   //Descomente essa linha caso utilizar um Arduino UNO
#define Mega   //Descomente essa linha caso utilizar um Arduino Mega

#ifdef Uno
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
#endif

#ifdef Mega
SpeedData SData(&Serial1);		// Serail 1 Mega
#endif

#ifdef Uno
SpeedData SData(&mySerial);		// SoftwareSerial Uno
#endif

void setup() {
  #ifdef Uno
  mySerial.begin(115200); //Serial dedicada ao acesso Can do Speeduino via Serial3
  Serial.begin(115200); 
  #endif

  #ifdef Mega
  Serial.begin(115200); 
  Serial1.begin(115200);  //Deletar essa linha caso esteja usando um ARDUINO UNO ou similar
  #endif
 
}

void loop() {

int RPM = SData.getRPM(500);
float AFR = SData.getActualAFR(100);

Serial.print ("RPM: ");Serial.print(RPM); Serial.print ("     AFR: ");Serial.println(AFR);
delay(1000);



   
}
