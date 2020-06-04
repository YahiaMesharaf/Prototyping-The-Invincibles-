 int check_Obstracles()
 int Distance
{
 if ( FrontSensor() < Distance && RightSensor () <Distance && LeftSensor 
()<Distance) // obstacle infront of all 3 sides
 {
turn_right (); 

}

 
 else if (FrontSensor() <Distance && RightSensor () <Distance && LeftSensor 
()>Distance) // obstacle on right and front sides
 {
 turn_left (); // turn left side
 }


 
 else if (FrontSensor() <Distance && RightSensor () >Distance && LeftSensor 
()<Distance) // obstacle on left and front sides
    {
 turn_right (); // turn right side
 }


 else if (FrontSensor() <Distance && RightSensor () >Distance && LeftSensor 
()>Distance) // obstacle on front sides
 {
 turn_right (); // then turn right
 }


 else if (FrontSensor() >Distance && RightSensor () >Distance && LeftSensor 
()<Distance) // obstacle on left sides
 {
 turn_right (); // then turn right and then forward
 for(int i=0;i<=180;i++)
 {
 
 forward();
 
 }
 }

 
 else if (FrontSensor() >Distance && RightSensor () <Distance && LeftSensor 
()>Distance) // obstacle on right sides
 {
 turn_left (); // then turn left and then right
 for(int i=0;i<=180;i++)
 {
 forward();
}
 }

 
 else 
 {
 forward();
 }
 return 0;
}
