int soundSensor = 7;
int LED = 3;
int val;
void setup() 
{

  pinMode (soundSensor, INPUT);
  pinMode (LED, OUTPUT);
}

void loop()
{
  val=digitalRead(soundSensor);
  
  if (val==HIGH)
  {
    digitalWrite(LED, HIGH);
  }
  
  else
  {
    digitalWrite(LED, LOW);
  }
  
}
