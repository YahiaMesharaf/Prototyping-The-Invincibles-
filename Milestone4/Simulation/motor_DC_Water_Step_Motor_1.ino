
#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int rolePerMinute = 10;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

// initialize the stepper library on pins 10 through 13:
Stepper myStepper(stepsPerRevolution, 10, 11, 12, 13);


const int waterSens = A0; //define water sensor
const int led = 5;//define led to pin 9
int waterVal; //define the water sensor value

const int pwm = 2;
const int in_1 = 8; const int in_2 = 9;

void setup() { 
  pinMode(pwm,OUTPUT);
  pinMode(in_1,OUTPUT);
  pinMode(in_2,OUTPUT);
  pinMode(led, OUTPUT); //set led as an output
  pinMode(waterSens, INPUT);//set water sensor as an input
  Serial.begin(9600);  //start the serial port at 9600 bauds

  myStepper.setSpeed(rolePerMinute);
  // initialize the serial port:
  Serial.begin(9600);
  }

void loop() {

 waterVal = analogRead(waterSens); //read the water sensor
  
  Serial.println(waterVal); //print the value of the water sensor to the serial monitor
  

if (waterVal <= 0){
  //if the water sensor senses water turn the led on


// step one revolution  in one direction:
  Serial.println("Land Motor");
  myStepper.step(stepsPerRevolution);
  delay(100);

  

}
else{


  //for clock wise motion

digitalWrite(in_1,HIGH); digitalWrite(in_2,LOW); analogWrite(pwm,130);

//delay for 3 sec Clock wise motion
Serial.println("Water Motor");
delay(1000);

//for break

digitalWrite(in_1,HIGH); digitalWrite(in_2,HIGH); delay(200);

//for anticlock wise

digitalWrite(in_1,LOW); digitalWrite(in_2,HIGH); delay(3000);

//for break

digitalWrite(in_1,HIGH); digitalWrite(in_2,HIGH); delay(200);
}
}
