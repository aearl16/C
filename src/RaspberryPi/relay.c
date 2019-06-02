/*
*@Author: Aaron Earl
*6/2/19
*
*From Freenove RPi tutorials
*Ch.14 Relay and Motor
*
*Task: Use a relay to control a motor
*/

#include <wiringPi.h>
#include <stdio.h>

#define relayPin 0  //define the relay pin
#define buttonPin 1 //define the button pin

//global variables
int relayState = LOW;		//store the state of the relay
int buttonState = HIGH;		//store the state of the button
int lastButtonState = HIGH; //store the last state of the button
long lastChangeTime;		//store the change time of button state
long captureTime = 50;		//set the button state stable time
int reading;

int main(void)
{
	if(wiringPiSetup() == -1)
	{
		printf("wiringPi setup failed!");
		return 1;
	}

	printf("Program is starting...\n");

	pinMode(relayPin, OUTPUT);
	pinMode(buttonPin, INPUT);
	pullUpDnControl(buttonPin, PUD_UP); //pull up too high level

	while(1)
	{
		reading = digitalRead(buttonPin); //read the current state of button

		//if the button state has changed, record the time point
		if(reading != lastButtonState)
		{
			lastChangeTime = millis();
		}

		/*
		*if changing state of the button is beyond the laswt set time,
		*we consider the button state is a valid change rather than
		*buffeting.
		*/
		if(millis() - lastChangeTime > captureTime)
		{
			//if button state is changed, update the data.
			if(reading != buttonState)
			{
				buttonState = reading;
				//if the state is low, the action is pressing
				if(buttonState == LOW)
				{
					printf("Button has been pressed!\n");
					relayState = !relayState;
					if(relayState)
					{
						printf("Turn on relay...\n");
					}
					else
					{
						printf("Turn off relay...\n");
					}
				}
				//if the state is high, the action is releasing
				else
				{
					printf("Button has been released!\n");
				}
			}
		}

		digitalWrite(relayPin, relayState);
		lastButtonState = reading;

	}

	return 0;
}
