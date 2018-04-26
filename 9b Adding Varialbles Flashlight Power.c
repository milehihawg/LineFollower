#pragma config(Sensor, in1,    LFR,            sensorLineFollower)
#pragma config(Sensor, in2,    LFM,            sensorLineFollower)
#pragma config(Sensor, in3,    LFL,            sensorLineFollower)
#pragma config(Sensor, in4,    Pot,            sensorPotentiometer)
#pragma config(Sensor, dgtl2,  Sonar,          sensorSONAR_inch)
#pragma config(Sensor, dgtl5,  Button,         sensorTouch)
#pragma config(Sensor, dgtl6,  LEDRed,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl7,  LEDYellow,      sensorLEDtoVCC)
#pragma config(Sensor, dgtl8,  LEDGreen,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl9,  RightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, LeftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           Flashlight,    tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           RightMotor,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           LeftMotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
/*
Pseudacode or comments for the coder

*/
int FLP;//Flashlight Power
float TimeDelay=.04;
task main()
{
	while (1==1)
	{
		FLP=0;
		while (FLP<127)
		{
			FLP++;//This takes FLP ingrement by 1
			turnFlashlightOn(Flashlight, FLP);
			//waitInMilliseconds(TimeDelay);
			wait(TimeDelay);

		}

		while (FLP>-1)
		{
			FLP--; //Step down the flashlight
			turnFlashlightOn(Flashlight, FLP);
			//waitInMilliseconds(TimeDelay);
			wait(TimeDelay);
		}
	}


}
