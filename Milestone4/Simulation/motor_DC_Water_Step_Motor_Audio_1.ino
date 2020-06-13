
#include <Stepper.h>

int  sensorAnalogPin = A1;    // Select the Arduino input pin to accept the Sound Sensor's analog output 
int  sensorDigitalPin = 7;    // Select the Arduino input pin to accept the Sound Sensor's digital output
int  analogValue = 0;         // Define variable to store the analog value coming from the Sound Sensor
int  digitalValue;            // Define variable to store the digital value coming from the Sound Sensor
int  Led13 = 3;              
const int buzzer = 6;         //buzzer to arduino pin 6


const int stepsPerRevolution = 2048;  //  the number of steps per revolution
const int rolePerMinute = 10;         //  range stepper is 0-17 rpm

// initialize the stepper library on pins 10 through 13:
Stepper myStepper(stepsPerRevolution, 10, 11, 12, 13);


const int waterSens = A0; //define water sensor
const int led = 5;//define led to pin 9
int waterVal; //define the water sensor value

const int pwm = 2;
const int in_1 = 8; const int in_2 = 9;

void setup() { 

  Serial.begin(9600);               
  pinMode(sensorDigitalPin,INPUT);  // Define pin 7 as an input port, to accept digital input
  pinMode(Led13,OUTPUT);  // Define LED13 as an output port, to indicate digital trigger reached
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 6 as an output


  
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


 digitalWrite(buzzer,HIGH);
  
  analogValue = analogRead(sensorAnalogPin); // Read the value of the analog interface A1 assigned to digitalValue 
  digitalValue=digitalRead(sensorDigitalPin); // Read the value of the digital interface 7 assigned to digitalValue 
  Serial.println(analogValue); // Send the analog value to the serial transmit interface
  Serial.println(digitalValue);
  if(digitalValue==HIGH)      // When the Sound Sensor sends signla, via voltage present, light LED13 
  {
    digitalWrite(Led13,HIGH);
  }
  else
  {
    digitalWrite(Led13,LOW);
  }
  
  delay(50);                  // Slight pause so that we don't overwhelm the serial interface




}
