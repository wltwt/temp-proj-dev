#include <Arduino.h>
#include <Wire.h>

#define SDA 16
#define SCL 17



void setup() {

  Wire.begin();
  
}

void loop() {
  static int x = 0;


  Wire.beginTransmission(0x01);
  Wire.write("x is");
  Wire.write(x);
  Wire.endTransmission();
  x++;

  delay(500);


}
