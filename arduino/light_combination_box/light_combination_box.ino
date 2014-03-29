/* Light Combination Box
 by Becky Stewart 
 for Codasign
 March 2014
 
 Select the correct LED by turning
 the knob in order to open the box. 
 
 Components
 servo on Pin 9
 leds on Pins 3-8
 pot on A0
 pot on A1
 */

#include <Servo.h> 

int boxPin = 9;
int led1 = 3;
int led2 = 4;
int led3 = 5;
int potPin = A0;

Servo boxServo;
int openPos = 100; // adjust this number
int closedPos = 0; // and this number for your box
int boxOpen;      // whether box is open or closed

// setup runs once when first started
void setup() {
  // set up the pin modes
  pinMode( boxPin, OUTPUT );
  pinMode( led1, OUTPUT );
  pinMode( led2, OUTPUT );
  pinMode( led3, OUTPUT );

  boxServo.attach(9);

  closeBox(); // begin with box closed
  Serial.begin( 9600 );
}

// loop runs repeatedly
void loop() {
  int potValue = digitalRead( potPin );

  if( potValue <= 85 ) {
    Serial.println("close the box");
    closeBox();
    digitalWrite( led1, HIGH );  // turn on LED
    digitalWrite( led2, LOW );  // turn off LED
    digitalWrite( led3, LOW );  // turn off LED
  }
  if( potValue > 85 && potValue <= 170 ) {
    Serial.println("open the box");
    openBox();
    digitalWrite( led1, LOW );  // turn off LED
    digitalWrite( led2, HIGH );  // turn on LED
    digitalWrite( led3, LOW );  // turn off LED
  }
  if( potValue > 170 ) {
    Serial.println("close the box");
    closeBox();
    digitalWrite( led1, LOW );  // turn off LED
    digitalWrite( led2, LOW );  // turn off LED
    digitalWrite( led3, HIGH );  // turn on LED
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



