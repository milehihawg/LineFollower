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
The LED's will turn on based on the black line under the line followers LEFT, Mid, RIGHT.
Loop Forever
The Red LED will turn on if the left line follower reads greater than 2000.
The Yellow LED will turn on if the middle line follower reads greater than 2000.
The Green LED will turn on if the right line follower reads greater than 2000.
*/
task main()
{
	untilBump(Button, 20);// Starts the Robot the first time

	while (1==1)
	{
		if (SensorValue[Button]==1)//It is ==1 because the button is pressed.
		{
			stopMotor(LeftMotor);// Making sure the Robot doesn't move or in an emergency
			stopMotor(RightMotor);
			waitInMilliseconds(30);
			while (SensorValue[Button]==1)// Waiting for the button to be released for the next button push
			{}
			waitInMilliseconds(20);// clears all the noice from above.
			untilBump(Button, 20);// 20 milliseconds wait for before "key debounce"

		}
		if (SensorValue[LFR]>2000 && SensorValue[LFM]>2000 && SensorValue[LFL]>2000)//All Line Followers High.
		{
			stopMotor(LeftMotor);// Making sure the Robot doesn't move or in an emergency
			stopMotor(RightMotor);
			while (SensorValue[Button]==1)// Waiting for the button to be released for the next button push
			{}
			waitInMilliseconds(20);// clears all the noice from above.
			untilBump(Button, 20);// 20 milliseconds wait for before "key debounce"

		}
		if (SensorValue[LFR]>2000)
		{
			turnLEDOff(LEDGreen);
			turnLEDOn(LEDRed);
			turnLEDOff(LEDYellow);
			startMotor(LeftMotor, 75);
			stopMotor(RightMotor);
		}
		if (SensorValue[LFM]>2000)
		{
			turnLEDOff(LEDGreen);
			turnLEDOff(LEDRed);
			turnLEDOn(LEDYellow);
			startMotor(LeftMotor, 75);
			startMotor(RightMotor, 75);
		}
		if (SensorValue[LFL]>2000)
		{
			turnLEDOn(LEDGreen);
			turnLEDOff(LEDRed);
			turnLEDOff(LEDYellow);
			startMotor(RightMotor, 75);
			stopMotor(LeftMotor);
		}
	}

}
