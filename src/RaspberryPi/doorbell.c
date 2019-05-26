/*
*@Author: Aaron Earl
*5/25/19
*
*From Freenove RPi Tutorial
*Ch.6 Buzzer
*
*/

#include <wiringPi.h>
#include <stdio.h>

#define buzzerPin	0	//define the buzzer pin
#define buttonPin	1	//define the button pin

int main(void)
{
	if(wiringPiSetup() == -1)
	{
		printf("wiringPi setup failed!");
		return 1;
	}

	pinMode(buzzerPin, OUTPUT);
	pinMode(buttonPin, INPUT);

	pullUpDnControl(buttonPin, PUD_UP);	//Pull up to high level

	while(1)
	{
		if(digitalRead(buttonPin) == LOW) //Button has been pressed down
		{
			digitalWrite(buzzerPin, HIGH); //Buzzer on
			printf("buzzer on....\n");
		}
		else //button released
		{
			digitalWrite(buzzerPin, LOW); //Buzzer off
			printf("buzzer off....\n");
		}
	}

	return 0;
}
