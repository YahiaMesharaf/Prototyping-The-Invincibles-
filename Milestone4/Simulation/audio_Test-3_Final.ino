int  sensorAnalogPin = A1;    // Select the Arduino input pin to accept the Sound Sensor's analog output 
int  sensorDigitalPin = 7;    // Select the Arduino input pin to accept the Sound Sensor's digital output
int  analogValue = 0;         // Define variable to store the analog value coming from the Sound Sensor
int  digitalValue;            // Define variable to store the digital value coming from the Sound Sensor
int  Led13 = 3;              // Define LED port; 
 const int buzzer = 6;         //buzzer to arduino pin 6
                              
                              

void setup()
{
  Serial.begin(9600);               /
  pinMode(sensorDigitalPin,INPUT);  // Define pin 7 as an input port, to accept digital input
  pinMode(Led13,OUTPUT);  // Define LED13 as an output port, to indicate digital trigger reached
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 6 as an output
}

void loop(){

 digitalWrite(buzzer,HIGH);
  
  analogValue = analogRead(sensorAnalogPin); // Read the value of the analog interface A1 assigned to digitalValue 
  digitalValue=digitalRead(sensorDigitalPin); // Read the value of the digital interface 7 assigned to digitalValue 
  Serial.println(analogValue); // Send the analog value to the serial transmit interface
  Serial.println(digitalValue);
  if(digitalValue==HIGH)      
  {
    digitalWrite(Led13,HIGH);
  }
  else
  {
    digitalWrite(Led13,LOW);
  }
  
  delay(50);                  // Slight pause so that we don't overwhelm the serial interface



}
