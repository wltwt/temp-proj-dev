#include <Arduino.h>
#include <Wire.h>
#include <Zumo32U4.h>



Zumo32U4ButtonC buttonC;
Zumo32U4OLED display;
int x;
void receiveEvent(int howMany);

void setup() {
  Serial.begin(115200);

  Wire.begin(0x01);

  Wire.onReceive(receiveEvent); // register event
}

void loop() {
  // Clear the screen
  display.clear();
  // Print a string
  display.print("hi");
  // Go to the next line
  display.gotoXY(0, 1);
  // Print a number
  display.print(x);

  delay(100);
}


void receiveEvent(int howMany)
{
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    display.print(c);      // print the character
  }
  x = Wire.read();    // receive byte as an integer  
  

}