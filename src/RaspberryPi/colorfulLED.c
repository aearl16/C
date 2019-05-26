/*
*@Author: Aaron Earl
*5/25/19
*
* from Freenove RPi tutorials
* Ch.5 RGBLED
*/

#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define ledPinRed   0
#define ledPinGreen 1
#define ledPinBlue  2

void ledInit(void)
{
	softPwmCreate(ledPinRed, 0, 100);
	softPwmCreate(ledPinGreen, 0, 100);
	softPwmCreate(ledPinBlue, 0, 100);
}

void ledColorSet(int r_val, int g_val, int b_val)
{
	softPwmWrite(ledPinRed, r_val);
	softPwmWrite(ledPinGreen, g_val);
	softPwmWrite(ledPinBlue, b_val);
}

int main(void)
{
	int r, g, b;

	if(wiringPiSetup() == -1)
	{
		printf("WiringPi setup failed!");
		return 1;
	}

	printf("Program starting....\n");
	ledInit();

	while(1)
	{
		r = random() % 100;
		g = random() % 100;
		b = random() % 100;
		ledColorSet(r, g, b);
		printf("r = %d, g = %d, b = %d\n", r, g, b);
		delay(300);
	}

	return 0;
}
