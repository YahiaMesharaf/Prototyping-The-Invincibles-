#include <Arduino.h>
#include<iostream>

#define pwm 2
#define in_1 8
#define in_2 9
#define waterSens A0

int waterValue;
int init[2]{0,0};
int goal[2]{4,5};

void setup()
{
  // put your setup code here, to run once:
  pinMode(pwm, OUTPUT);
  pinMode(in_1, OUTPUT);
  pinMode(in_2, OUTPUT);
  pinMode(waterSens, INPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  waterValue = analogRead(waterSens); 
  Drive();
}

void ActivateDC()
{

  //for clock wise motion

  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, LOW);
  analogWrite(pwm, 130);

  //delay for 3 sec Clock wise motion

  delay(1000);

  //for break

  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, HIGH);
  delay(200);

  //for anticlock wise

  digitalWrite(in_1, LOW);
  digitalWrite(in_2, HIGH);
  delay(3000);

  //for break

  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, HIGH);
  delay(200);
}

void ActivatePropeller()
{

  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, LOW);
  analogWrite(pwm, 130);

  //delay for 3 sec Clock wise motion

  delay(1000);

  //for break

  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, HIGH);
  delay(200);

  //for anticlock wise

  digitalWrite(in_1, LOW);
  digitalWrite(in_2, HIGH);
  delay(3000);

  //for break

  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, HIGH);
  delay(200);
}

void Drive() {
    auto drivePath = ReadBoardFile("environment.board");
    if (waterValue <= 0)  {
        ActivateDC();
        std::cout<<"Water Mode Drive Activted \n";
    }
  } else {
    ActivatePropeller();
    std::cout<<"Water Mode Drive Activted \n";
  }
  Search(environment, init, goal);
}