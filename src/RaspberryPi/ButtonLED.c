/*
*@Author: Aaron Earl
*
* Tutorial from Freenove RPi Tutorials
*
* Task: Make and LED turn on or
* off based on a button state
*/

#include <wiringPi.h>
#include <stdio.h>

#define ledPin    0
#define buttonPin 1

int main(void)
{

	if(wiringPiSetup() == -1)
	{
		printf("Setup of wiringPi failed!\n");
		return 1;
	}

	pinMode(ledPin, OUTPUT);
	pinMode(buttonPin, INPUT);

	pullUpDnControl(buttonPin, PUD_UP); //pull up to high level
	
	while(1)
	{
		if(digitalRead(buttonPin) == LOW) //button has been pressed
		{
			digitalWrite(ledPin, HIGH); //led on
			printf("LED On...\n");
		}
		else //button released
		{
			digitalWrite(ledPin, LOW);
			printf("...LED Off\n");
		}
	}

	return 0;
}
