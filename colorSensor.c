#pragma config(Sensor, port3,  colorl,         sensorVexIQ_ColorGrayscale)
#pragma config(Sensor, port4,  colorr,         sensorVexIQ_ColorGrayscale)
#pragma config(Motor,  motor1,          motorl,        tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor6,          motorr,        tmotorVexIQ, PIDControl, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{   
    resetMotorEncoder(motorl)
	resetMotorEncoder(motorr)
	while(getMotorEncoder(motorl) < 1000)

	{
		if(getColorGrayscale(colorl)< 100 && getColorGrayscale(colorr)< 100)
	    	{
		    	setMotorSpeed(motorr, 50);
			    setMotorSpeed(motorl, 50);
    		}
	   	else if(getColorGrayscale(colorl)> 100 && getColorGrayscale(colorr)< 100)
	        {
	       		setMotorSpeed(motorr, 0);
		    	setMotorSpeed(motorl, 50);
	       	}
    	else if(getColorGrayscale(colorl)< 100 && getColorGrayscale(colorr)> 100)
        	{
	        	setMotorSpeed(motorr, 50);
			    setMotorSpeed(motorl, 0);
    	   	}
	}
}