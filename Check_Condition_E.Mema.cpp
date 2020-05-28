int Check_Condition(response)//Response is the signal that we get from sensors 
{
  	
  	do
    	{
      	check_Obstracles();// Continue driving
	} while ((response != '1') && (response != '2') ); //1-Dangerrous Environment and 2-Rescue object is reached

  	if (response == '1')//Dangerrous Environment 
  	 printf("Aprochin Dangerrous Environment");
    		return 1;
    else if(response == '2')//Rescue object is reached
    printf("Rescue object is reached");
            return 2:
  	else
    		return 0;
    	
}
