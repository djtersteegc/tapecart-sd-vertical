/*
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 10
*/

#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  pinMode(8, OUTPUT); //Red Write LED
  pinMode(3, OUTPUT); //Green Read LED


  if (!SD.begin(10)) {
    digitalWrite(8, HIGH);   // turn the Red Write LED on if unable to connect to the SD card
    while (1);
  }
  
  myFile = SD.open("browser.prg");
  
  if (!myFile) {
    digitalWrite(3, HIGH);   // turn the Green Read LED on if unable to open the browser.prg file on the root of the SD card
    while (1);
  }
}

void loop() {
  // If SD card tests worked, flash both LED's on and off forever
  
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for half a second
  digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for half a second
}
