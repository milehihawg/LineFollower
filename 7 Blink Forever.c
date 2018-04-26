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
This program turns on the LED
for 1 second and then turns off
the LED for one second repeatedly.
*/
task main()
{
	while(1 == 1)
	{
		turnLEDOn(LEDRed);
		waitInMilliseconds(1000);

		turnLEDOff(LEDRed);
		waitInMilliseconds(1000);
	}
}
