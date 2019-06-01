/*
*@Author: Aaron Earl
*6/1/19
*
*From Freenove RPi tutorials
*Ch.12 Joystick
*
*Note: Circuit same from last lab. AIN0
*connected to VRY pin on joystick and
*AIN1 connected to VRX.
*GPIO connected to SW on joystick driving
*z dir.
*
*Note 2: Correction from tutorial; softPwm.h not
*needed and -l m not needed as math.h wasn't
*included for any calculations
*/

#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>

#define address 0x48 //default address of pcf8591
#define pinbase 64	 //any number above 64
#define A0 pinbase + 0
#define A1 pinbase + 1
#define A2 pinbase + 2
#define A3 pinbase + 3
#define Z_Pin 1		//define pin for z axis

int main(void)
{
	int val_X, val_Y, val_Z;

	if(wiringPiSetup() == -1)
	{
		printf("wiringPi setup failed!");
		return 1;
	}

	pinMode(Z_Pin, INPUT); //Set Z_Pin as input and pull-up mode
	pullUpDnControl(Z_Pin, PUD_UP);

	pcf8591Setup(pinbase, address); //initialize pcf8591

	while(1)
	{
		val_Z = digitalRead(Z_Pin); //read digital value of axis z
		val_Y = analogRead(A0);     //read analog value of axis X and Y
		val_X = analogRead(A1);

		printf("val_X: %d, \tval_Y: %d, \tval_Z: %d\n", val_X, val_Y, val_Z);
		delay(100);

	}

	return 0;
}
