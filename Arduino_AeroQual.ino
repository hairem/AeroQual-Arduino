#include <Adafruit_ADS1015.h>
#include <SPI.h>
#include <Wire.h>

Adafruit_ADS1115 ads1(0x48);
Adafruit_ADS1115 ads2(0x49);

void setup() {
 Wire.begin();
 Serial.begin(9600);

 
 ads1.begin();
 ads2.begin();
}

void loop() {
float multiplier = 0.1875F;
int16_t results1;int16_t results2;int16_t results3;int16_t results4;
results1 = ads1.readADC_Differential_0_1();
results2 = ads1.readADC_Differential_2_3();
results3 = ads2.readADC_Differential_0_1();
results4 = ads2.readADC_Differential_2_3();
float ozone1 = results1*multiplier*10.000;
float ozone2 = results2*multiplier*10.000;
float ozone3 = results3*multiplier*10.000;
float ozone4 = results4*multiplier*10.000;


//Serial Output
Serial.print(ozone1/100);Serial.print(" "); Serial.print(ozone2/100);Serial.print(" ");Serial.print(ozone3/100);Serial.print(" ");Serial.println(ozone4/100);

 delay(15000);
}
