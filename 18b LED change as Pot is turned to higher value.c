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
LED Red, Yellow, and Green are turned on as Pot is turned to higher value.
Loop Forever
If Pot value is less than 1365 Green should be on only
If Pot value is greater than 2729 Red should be on only
If Pot value is in between the above values the Yellow should be on only
*/
int PotVal;
task main()
{
	while (1==1)
	{
		PotVal=SensorValue[Pot];
		if (PotVal<1365)
		{
			turnLEDOn(LEDGreen);
			turnLEDOff(LEDRed);
			turnLEDOff(LEDYellow);
		}
		if (PotVal>2729)
		{
			turnLEDOff(LEDGreen);
			turnLEDOn(LEDRed);
			turnLEDOff(LEDYellow);
		}
		if (PotVal>1365&&PotVal<2729)//two && symbols gives the Boolean AND, OR "||" double pipe
		{
			turnLEDOff(LEDGreen);
			turnLEDOff(LEDRed);
			turnLEDOn(LEDYellow);
		}
	}
}
