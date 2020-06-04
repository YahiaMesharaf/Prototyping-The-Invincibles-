int Rescue()
{
  // example

  while(rescue='1') //Rescue object is nearby
  {
    if(door_closed)//The door or cover is locked 
    {
    	
      if(front_sensor='1') //Sensor detect the target
      {
        open_door();
        if(open_door='1');//Door open successfully
        {
        	Give_help ();
        	{
			
        	if(give_help='1')//object is rescued 
        	 printf("Help received");
        	 else()
        	 {
			 
        	 printf("Help not received");
        	 Manual_Help_On(); //The help is controlled manually 
            }
		}
		else {
		
		printf("Door could not open automaticaly");
		Manual_Mode_ON();//The door is open manually
		
	}
      }
      else 
      locate_target();//Sensor searching for the target
    }

  } 

  return 0;
}
}
