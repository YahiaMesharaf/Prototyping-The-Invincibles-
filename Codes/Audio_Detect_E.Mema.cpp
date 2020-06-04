Audio_Detect()
{
	if(mic==1)//Surveillance mode on 
	{
		if(Mic_on=1)//Mic turn on successfully
		{
			while(1)
			{
			printf("Watting for audio signal");	
			if(Signal=true)
			{
				Record_signal_Analog();//get the  analog signal 
				ADC();//Convert singnal from analog to digital
				time_sample_intervals();//check the range of signal and analyze all information 
				ferquency();//detetc the wave frequency
				DAC();//Convert singnal from digita to analog
				
			}
			else
			{
			printf("Audio signal undefined");
			Analyze_Manual_Mode_on();//The audio semple is analyzed manually		
			}
			}
		}
		else
		{
			printf("Mic could not tur on automatyclly");
			Mic_On _Manual_Mode();
		
		}
	}
	
}
