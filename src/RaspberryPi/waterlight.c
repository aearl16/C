/*
*
*@Author: Aaron Earl
*
* Tutorial from Freenove RPi tutorials
*
* Task: create a flowing water light
* w/an LED bar graph light
*
* Note: Original code from Freenove
* had errors in it. My code may be
* modified from the original tutorial.
*
* Special Note: If the LED bar graph
* doesn't light the device may be reversed.
* The anode side on my devive isn't labeled,
* and it may be the same on yours.
*/

#include <wiringPi.h>
#include <stdio.h>

#define leds 10

int pins[leds] = {0,1,2,3,4,5,6,7,8,9};

void led_on(int n) //Make led_n on
{
	digitalWrite(n, LOW);
}

void led_off(int n) //Make led_n off
{
	digitalWrite(n, HIGH);
}

int main(void)
{
	int i;
	printf("Program is starting...\n");
	if(wiringPiSetup() == -1)
	{
		printf("Setup of wiringPi failed!\n");
		return 1;
	}

	for(i = 0; i < leds; ++i)
	{
		pinMode(pins[i], OUTPUT); //Set LED pins to OUTPUT
	}

	while(1)
	{
		for(i = 0; i < leds; ++i) //Make LEDs on from left to right
		{
			led_on(pins[i]);
			delay(100);
			led_off(pins[i]);
		}
		for(i = leds - 1; i > -1; --i) //Make LEDs on from right to left
		{
			led_on(pins[i]);
			delay(100);
			led_off(pins[i]);
		}
	}

	//Turn off all of the pins before termination
	for(i = 0; i < leds; ++i)
	{
		led_off(pins[i]);
	}
	return 0;
}
