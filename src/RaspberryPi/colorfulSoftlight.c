/*
*@Author: Aaron Earl
*5/27/19
*
*From Freenove RPi tutorials
*Ch.9 Potentiometer and RGBLED
*
*Note: Wiring setup is similar to last
*lab. Changes are pins AIN1, AIN2 are
*are connected to potentiometers and
*the RGBLED
*/

#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>
#include <softPwm.h>

#define address 0x48	//pcf8591 default address
#define pinbase 64		//any number above 64
#define A0 pinbase + 0
#define A1 pinbase + 1
#define A2 pinbase + 2
#define A3 pinbase + 3

//Define 3 pins for RGBLED
#define ledRedPin	3
#define ledGreenPin 2
#define ledBluePin	0

int main(void)
{
	int val_Red, val_Green, val_Blue;

	if(wiringPiSetup() == -1)
	{
		printf("wiringPi setup failed!");
		return 1;
	}

	//Create 3 PWM output pins for RGBLED
	softPwmCreate(ledRedPin, 0, 100);
	softPwmCreate(ledGreenPin, 0, 100);
	softPwmCreate(ledBluePin, 0, 100);

	//Initialize PCF8591
	pcf8591Setup(pinbase, address);

	while(1)
	{
		//Read values of the 3 potentiometers
		val_Red = analogRead(A0);
		val_Green = analogRead(A1);
		val_Blue = analogRead(A2);

		//Map the read value of the potentiometers into PWM value and ouput
		softPwmWrite(ledRedPin, val_Red * 100 / 255);
		softPwmWrite(ledGreenPin, val_Green * 100 / 255);
		softPwmWrite(ledBluePin, val_Blue * 100 / 255);

		//Print out the read ADC Value
		printf("ADC value val_Red: %d, \tval_Green: %d, \tval_Blue: %d\n",
		val_Red, val_Green, val_Blue);

		delay(100);

	}

	return 0;
}

