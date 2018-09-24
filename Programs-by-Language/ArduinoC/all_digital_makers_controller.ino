#include "makerscontroller.h"

//directional buttons
int inPinRed = 5;     //red push button connected to pin 5
int inPinBlue = 7;     //blue push button connected to pin 7
int inPinGreen = 10;    //green push button connected to pin 10
int inPinYellow = 13;   //yellow push button connected to pin 13

//action buttons
int inPinDigitalOne = 8;   //red digital push button connected to pin 8
int inPinDigitalTwo = 8;   //red digital push button connected to pin 8
int inPinDigitalThree = 8;   //red digital push button connected to pin 8
int inPinDigitalFour = 8;   //red digital push button connected to pin 8
int inPinDigitalFive = 8;   //red digital push button connected to pin 8
int inPinDigitalSix = 8;   //red digital push button connected to pin 8


//start and select
int inPinStart;
int inPinSelect;

char *moveDirection = "string";      //direction to be printed to the screeen

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);       //open the serial port at 9600 bps
  pinMode( inPinRed, INPUT );
  pinMode( inPinBlue, INPUT );
  pinMode( inPinGreen, INPUT );
  pinMode( inPinYellow, INPUT );
  pinMode( inPinDigitalOne, INPUT );  
  
}

//button mappings are: red = up, blue = down, green = left, yellow = right
void loop() {
  // put your main code here, to run repeatedly:

  //initialize the current states of the controllers
  controller c1, c2;

  //read the data from the controllers
  readController( c1, c2 );
  
  delay( 1000 );      //delay 300 ms until next read
}

void readController( controller c1, controller c2 ){
  //read values from the digital buttons
  c1.buttonOne = !digitalRead( inPinDigitalOne );
  c1.buttonTwo = !digitalRead( inPinDigitalOne );
  c1.buttonThree = !digitalRead( inPinDigitalOne );
  c1.buttonFour = !digitalRead( inPinDigitalOne );
  c1.buttonFive = !digitalRead( inPinDigitalOne );
  c1.buttonSix = !digitalRead( inPinDigitalOne );

  //read values from the buttons - values are based on voltage 
  c1.buttonUp =  !digitalRead( inPinRed );
  c1.buttonDown =  !digitalRead( inPinBlue );
  c1.buttonLeft =  !digitalRead( inPinGreen );  
  c1.buttonRight =  !digitalRead( inPinYellow );

  //read values from start and select buttons
  c1.buttonSelect = !digitalRead( inPinDigitalOne );
  c1.buttonStart = !digitalRead( inPinDigitalOne );

  //again for c2
  c2.buttonOne = !digitalRead( inPinDigitalOne );
  c2.buttonTwo = !digitalRead( inPinDigitalOne );
  c2.buttonThree = !digitalRead( inPinDigitalOne );
  c2.buttonFour = !digitalRead( inPinDigitalOne );
  c2.buttonFive = !digitalRead( inPinDigitalOne );
  c2.buttonSix = !digitalRead( inPinDigitalOne );

  //read values from start and select buttons
  
  c2.buttonSelect = !digitalRead( inPinDigitalOne );
  c2.buttonStart = !digitalRead( inPinDigitalOne );

  //read values from the square gate "buttons"
  c2.buttonUp =  !digitalRead( inPinRed );
  c2.buttonDown =  !digitalRead( inPinBlue );
  c2.buttonLeft =  !digitalRead( inPinGreen );  
  c2.buttonRight =  !digitalRead( inPinYellow );

  //----------------this section is strictly for testing--------------------------
  
  //if only green(left) is pressed
  if( !c1.buttonUp && !c1.buttonDown && c1.buttonLeft && !c1.buttonRight ){
    moveDirection = "LEFT";
  }

  //if only yellow(right) is pressed
  else if( !c1.buttonUp && !c1.buttonDown && !c1.buttonLeft && c1.buttonRight ){
    moveDirection = "RIGHT";
  }
  
  //if red(up) is pressed
  else if( c1.buttonUp && !c1.buttonDown ){
    
    //if both red(up) and yellow(right) is pressed, set moveDirection to UPRIGHT
    if( c1.buttonRight ){
      moveDirection = "UPRIGHT";
    }

    //if both red(up) and green(left) is pressed, set moveDirection to UPLEFT
    else if( c1.buttonLeft ){
      moveDirection = "UPLEFT";
    }

    //only red is pressed
    else{
      moveDirection = "UP";
    }
  }

  //if blue(down) is pressed
  else if( !c1.buttonUp && c1.buttonDown ){

    //if both blue(down) and yellow(right) is pressed, set moveDirection to DOWNRIGHT
    if( c1.buttonRight ){
      moveDirection = "DOWNRIGHT";
    }

    //if both blue(down) and green(left) is pressed, set moveDirection to DOWNLEFT
    else if( c1.buttonLeft ){
      moveDirection = "DOWNLEFT";
    }

    //only blue(down) is pressed
    else{
      moveDirection = "DOWN";
    }
    
  }
 
  //No buttons were pressed since last cycle
  else{
    moveDirection = "NULL";
  }

  Serial.print( '\n' );
  Serial.print( "Player 1: ");
  Serial.print( '\n' );
  Serial.print( "Direction: " );
  Serial.print( moveDirection );
  Serial.print( ' ' );
  Serial.print( "Button 1: " );
  Serial.print( c1.buttonOne );
  Serial.print( c1.buttonUp );
  Serial.print( c1.buttonDown );
  Serial.print( c1.buttonLeft );
  Serial.print( c1.buttonRight );
  Serial.print( c1.buttonStart );
  Serial.print( c1.buttonSelect );

  Serial.print( '\n' );
  Serial.print( "Player 2: ");
  Serial.print( '\n' );
  Serial.print( "Direction: " );
  Serial.print( moveDirection );
  Serial.print( ' ' );
  Serial.print( "Button 1: " );
  Serial.print( c2.buttonOne );
  Serial.print( c2.buttonUp );
  Serial.print( c2.buttonDown );
  Serial.print( c2.buttonLeft );
  Serial.print( c2.buttonRight );
  Serial.print( c2.buttonStart );
  Serial.print( c2.buttonSelect );
  
 }

 void blankControllerData( controller c1, controller c2 ){
  c1.buttonOne = 0;
  c1.buttonTwo = 0;
  c1.buttonThree = 0;
  c1.buttonFour = 0;
  c1.buttonFive = 0;
  c1.buttonSix = 0;

  //read values from the buttons - values are based on voltage 
  c1.buttonUp =  0;
  c1.buttonDown =  0;
  c1.buttonLeft =  0;
  c1.buttonRight =  0;

  //again for c2
  c2.buttonOne = 0;
  c2.buttonTwo = 0;
  c2.buttonThree = 0;
  c2.buttonFour = 0;
  c2.buttonFive = 0;
  c2.buttonSix = 0;

  //read values from the buttons - values are based on voltage 
  c2.buttonUp =  0;
  c2.buttonDown =  0;
  c2.buttonLeft =  0;
  c2.buttonRight =  0;
 }
