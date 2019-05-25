/*
*@Author: Aaron Earl
*
*5/25/19
*
*From Freenove RPi tutorials
* Ch.4 Analog and PWM, Breathing LED
*/

#include <wiringPi.h>
#include <stdio.h>

#define ledPin 1 //Only GPIO18 can ouput PWM

int main(void)
{
	int i;

	if(wiringPiSetup() == -1)
	{
		printf("Setup wiringPi failed!");
		return 1;
	}

	pinMode(ledPin, PWM_OUTPUT); //PWM output mode

	while(1)
	{
		for(i = 0; i < 1024; i++)
		{
			pwmWrite(ledPin, i);
			delay(2);
		}

		delay(300);
		
		for(i = 1023; i > 0; i--)
		{
			pwmWrite(ledPin, i);
			delay(2);
		}

		delay(300);
	}

	return 0;
}
