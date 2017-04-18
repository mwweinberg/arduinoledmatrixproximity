#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>

Adafruit_IS31FL3731 ledmatrix = Adafruit_IS31FL3731();

//brightness range between 0 and 255
//range between 0-15
int x = 1;
//range between 0-8
int y = 1;

int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider
int photocellFixed;
int oldVal = 0;

void setup() {
  if (! ledmatrix.begin()) {
  Serial.println("IS31 not found");
  while (1);
  }
  Serial.println("IS31 found!");

}

void loop() {

  // reads the photoresistor
  photocellReading = analogRead(photocellPin);
  // converts the photoresistor reading into the range
  //of cells on the board
  //resistor reading can be from 8 to 70
  //board is only 0-15
  photocellFixed = map(photocellReading, 8, 70, 0, 15);
  //draws circle at point 0,4 with radius X that is 50 bright
  ledmatrix.fillCircle(0, 4, photocellFixed, 50);
  delay(1000);

  //wipes the screen if the value is new
  if (photocellFixed != oldVal){
     ledmatrix.fillScreen(0);
  }

  //sets the oldVal to the current Val so it changes next time
  oldVal = photocellFixed;


  
  }



