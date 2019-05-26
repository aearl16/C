/*
*@Author: Aaron Earl
*5/26/19
*
*From Freenove tutorials for RPi
*Ch.6 Buzzer
*
*Task: Use circuit from previous
*lab, create an alertor using a
*passive buzzer and PWM
*/

#include <wiringPi.h>
#include <stdio.h>
#include <softTone.h>
#include <math.h>

#define buzzerPin	0	//Define the buzzer pin
#define buttonPin	1	//Define the btton pin

void alertor(int pin)
{
	int x;
	double sinVal, toneVal;

	for(x = 0; x < 360; x++)	//The frequency is based on the sine curve
	{
		sinVal = sin(x * (M_PI / 180));
		toneVal = 2000 + sinVal * 500;
		softToneWrite(pin, toneVal);
		delay(1);
	}
}

void stopAlertor(int pin)
{
	softToneWrite(pin, 0);
}

int main(void)
{
	if(wiringPiSetup() == -1)
	{
		printf("wiringPi setup failed!");
		return 1;
	}

	pinMode(buzzerPin, OUTPUT);
	pinMode(buttonPin, INPUT);
	softToneCreate(buzzerPin);
	pullUpDnControl(buttonPin, PUD_UP); //Pull up to high level

	while(1)
	{
		if(digitalRead(buttonPin) == LOW) //Button has been pressed down
		{
			alertor(buzzerPin); //buzzer on
			printf("alertor on...\n");
		}
		else //Button released
		{
			stopAlertor(buzzerPin); //buzzer off
			printf("buzzer off...\n");
		}
	}

	return 0;
}
