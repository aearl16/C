/*
*
*@Author: Aaron Earl
*
* Tutorial from Freenove RPi tutorials
*
* Task: create a flowing water light
* w/an LED bar graph light
*
* Note: Code seems to have errors in it,
* doesn't run. Copied from Freenove
* tutorials.
*/

#include <wiringPi.h>
#include <stdio.h>

#define leds 10

int pins[leds] = {0,1,2,3,4,5,6,7,8,9,10};

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

	for(i = 0; i < leds; i++)
	{
		pinMode(pins[i], OUTPUT); //Set LED pins to OUTPUT
	}

	while(1)
	{
		for(i = 0; i < leds; i++) //Make LEDs on from left to right
		{
			led_on(pins[i]);
			delay(100);
			led_off(pins[i]);
		}
		for(i = leds - 1; i > -1; i--) //Make LEDs on from right to left
		{
			led_on(pins[i]);
			delay(100);
			led_off(pins[i]);
		}
	}

	return 0;
}
