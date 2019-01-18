/*
*@Author: Aaron Earl
*
* Tutorial from Freenove RPi tutorials
*
* Task: Make a lamp from a button and LED
* Note: Couldn't get this program to work with RPi.
* tutorials does say it is for UNO and Pi.
* maybe millis() func not available to Pi library?
*/

#include <wiringPi.h>
#include <stdio.h>

#define ledPin 0		//Pin 11 on the board
#define buttonPin 1		//Pin 12 on the board

int ledState = LOW;				//Store and initialize the state of the LED
int buttonState = HIGH;			//Store and initializze the state of the button
int lastButtonState = HIGH;		//Store the last state of the button
long lastChangeTime;			//Store the time between button state change
long captureTime = 50;			//Set the button stable time
int reading;

int main(void)
{
	if(wiringPiSetup() == -1)
	{
		printf("Setup of wiringPi failed!\n");
		return 1;
	}

	printf("Program starting...\n");
	pinMode(ledPin, OUTPUT);
	pinMode(buttonPin, INPUT);

	pullUpDnControl(buttonPin, PUD_UP);		//Pull up to high level
	while(1)
	{
		reading = digitalRead(buttonPin);	//Read the current state of the button
		if(reading != lastButtonState)		//If button state has changed record the time
		{
			lastChangeTime = millis();
		}
		/*If the button change state time is beyond the set button change time,
		the button change can occur with no buffeting*/
		if(millis() - lastChangeTime > captureTime)
		{
			//If button state changed, update the data
			if(reading != buttonState)
			{
				buttonState = reading;
				//If the state is LOW, the action is pressing
				if(buttonState = LOW)
				{
					printf("Button pressed!\n");
					ledState = !ledState; //Simple state inversion
					if(ledState) //IE if state = 1 or HIGH
					{
						printf("LED On...\n");
					}
					else
					{
						printf("LED Off...\n");
					}
				}
				else //If the button state is HIGH, the action is releasing
				{
					printf("Button released!\n");
				}
			}
		}

		digitalWrite(ledPin, ledState);
		lastButtonState = reading;
	}

	return 0;
}
