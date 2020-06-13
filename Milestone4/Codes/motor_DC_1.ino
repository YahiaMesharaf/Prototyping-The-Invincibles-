const int pwm = 2;

const int in_1 = 8;
const int in_2 = 9;

void setup() {
  pinMode(pwm,OUTPUT); 
  pinMode(in_1,OUTPUT);
  pinMode(in_2,OUTPUT); }

void loop() {

//for clock wise motion

digitalWrite(in_1,HIGH);
digitalWrite(in_2,LOW); 
analogWrite(pwm,130);

//delay for 3 sec Clock wise motion

delay(1000);

//for break

digitalWrite(in_1,HIGH);
digitalWrite(in_2,HIGH);
delay(200);

//for anticlock wise

digitalWrite(in_1,LOW);
digitalWrite(in_2,HIGH);
delay(3000);

//for break

digitalWrite(in_1,HIGH);
digitalWrite(in_2,HIGH);
delay(200);

}
