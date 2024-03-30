#include "Mouse.h"
#include "Encoder.h"

//Encoder stuff
#define MOUSE_SENS 11   //default 5
Encoder encoder(2, 1);
long wheel = 0;
long prev_wheel = 0;


void setup() {

  //setup pins
  //pinMode(2, INPUT);
  //pinMode(1, INPUT);

  Serial.begin(9600);
  Mouse.begin();
}


void loop() {

  //encodering
  wheel = encoder.read();

  //move mouse if wheel moves
  if(wheel != prev_wheel){
    //horizontal
    Mouse.move((wheel - prev_wheel) * MOUSE_SENS, 0);

    //update wheel position    
    prev_wheel = wheel;
  }
}
