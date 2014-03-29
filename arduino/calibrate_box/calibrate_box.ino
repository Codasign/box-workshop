/* Calibrate Box
 by Becky Stewart 
 for Codasign
 March 2014
 
 Opens and closes box on loop.
 
 Components
 servo on Pin 9
 */

#include <Servo.h> 

int boxPin = 9;

Servo boxServo;
int openPos = 100; // adjust this number
int closedPos = 0; // and this number for your box

// setup runs once when first started
void setup() {
  // set up the pin modes
  pinMode( boxPin, OUTPUT );

  boxServo.attach(9);
}

// loop runs repeatedly
void loop() {
  openBox();
  delay(1000);
  closeBox();
  delay(1000);
}

// close the box
void closeBox(){
  for(int pos = closedPos; pos < openPos; pos += 1) // goes from closedPos to openPos
  {                                   // in steps of 1 degree
    boxServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                        // waits 15ms for the servo to reach the position 
  } 
}

// open the box
void openBox(){

  for(int pos = openPos; pos>closedPos; pos-=1) // goes from openPos to closedPos 
  {                                   // in steps of 1 degree
    boxServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                        // waits 15ms for the servo to reach the position 
  } 
}


