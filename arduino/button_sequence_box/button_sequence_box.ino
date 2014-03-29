/* Button Sequence Box
 by Becky Stewart 
 for Codasign
 March 2014
 
 Hold down the right buttons in order
 to open the box.
 
 Components
 servo on Pin 9
 button on Pins 10-12
 */

#include <Servo.h> 

int boxPin = 9;
int buttonPin1 = 10;
int buttonPin2 = 11;
int buttonPin3 = 12;

Servo boxServo;
int openPos = 100; // adjust this number
int closedPos = 0; // and this number for your box
int boxOpen;      // whether box is open or closed

// setup runs once when first started
void setup() {
  // set up the pin modes
  pinMode( boxPin, OUTPUT );
  pinMode( buttonPin1, INPUT_PULLUP );
  pinMode( buttonPin2, INPUT_PULLUP );
  pinMode( buttonPin3, INPUT_PULLUP );

  boxServo.attach(9);

  closeBox(); // begin with box closed
  Serial.begin( 9600 );
}

// loop runs repeatedly
void loop() {
  // read in states of buttons
  int buttonState1 = digitalRead( buttonPin1 );
  int buttonState2 = digitalRead( buttonPin2 );
  int buttonState3 = digitalRead( buttonPin3 );

  if( buttonState1 == 0 && 
      buttonState2 == 1 &&
      buttonState3 == 1) {
    Serial.println("open the box");
    openBox();
  }
  else {
    Serial.println("close the box");
    closeBox();
  }
}

// close the box
void closeBox(){
  if( boxOpen ) {
    for(int pos = closedPos; pos < openPos; pos += 1) // goes from closedPos to openPos
    {                                   // in steps of 1 degree
      boxServo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                        // waits 15ms for the servo to reach the position 
    } 
  }
  boxOpen = false;
}

// open the box
void openBox(){
  if( !boxOpen ){
    for(int pos = openPos; pos>closedPos; pos-=1) // goes from openPos to closedPos 
    {                                   // in steps of 1 degree
      boxServo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                        // waits 15ms for the servo to reach the position 
    } 
  }
  boxOpen = true;
}



