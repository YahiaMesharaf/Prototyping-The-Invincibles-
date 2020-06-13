// define pins 
const  int greenPin =  4 ; 
const  int redPin =  3 ; 
const  int soundPin =  7 ;
 

boolean greenLedStatus =  false ;
 
// how long wait for sound? 
const  int pauseDelay =  200 ;
 
void setup ( )  { 
  // configure pins and set LEDs to start 
  Serial.begin(9600); 
  pinMode ( soundPin, INPUT ) ; 
  pinMode ( greenPin, OUTPUT ) ; 
  pinMode ( redPin, OUTPUT ) ; 
  digitalWrite ( greenPin, greenLedStatus ) ; 
  digitalWrite ( redPin ,! greenLedStatus ) ; 
}
 
void loop ( )  { 
  // read digital pin 7 and switch at LOW 
  int din = digitalRead ( soundPin ) ; 
  if  ( ! din )  { 
    greenLedStatus =  ! greenLedStatus ; 
    digitalWrite ( greenPin, greenLedStatus ) ; 
    digitalWrite ( redPin ,! greenLedStatus ) ; 
    // The HIGH is not entirely logical, since there is actually a LOW on the pin :) 
    Serial. println ("HIGH!" ) ; 
    delay ( pauseDelay ) ; 
  } 
}
