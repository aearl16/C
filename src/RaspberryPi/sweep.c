/*
*@Author: Aaron Earl
*6/2/19
*
*From Freenove RPi Tutorials
*Ch.15 Servo
*
*Task: Control a servo and drive
*from 0 - 180 degrees and back.
*
*Note: servo must be driven with PWM
*at 50Hz. Red line ==> 5V power,
*Brown ==> GND, Orange ==> PWM input.
*
*Servo chart:
*0.5ms ==> 0   deg
*1.0ms ==> 45  deg
*1.5ms ==> 90  deg
*2.0ms ==> 135 deg
*2.5ms ==> 180 deg
*/

#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

//define the unit of servo pulse offset: 0.1ms
#define OFFSET_MS 3
//define the pulse duration for minimum servo angle
#define SERVO_MIN_MS 5 + OFFSET_MS
//define the pulse duration for maximum servo angle
#define SERVO_MAX_MS 25 + OFFSET_MS
//servo control pin (GPIO18)
#define servoPin 1

long map(long value, long fromLow, long fromHigh, long toLow, long toHigh)
{
	return (toHigh - toLow) * (value - fromLow) / (fromHigh - fromLow) + toLow;
}

//Init function for servo PWM pin
void servoInit(int pin)
{
	softPwmCreate(pin, 0, 200);
}

//Secify a certain rotation angle (0-180)
void servoWrite(int pin, int angle)
{
	if(angle > 180)
	{
		angle = 180;
	}
	if(angle < 0)
	{
		angle = 0;
	}

	softPwmWrite(pin, map(angle, 0, 180, SERVO_MIN_MS, SERVO_MAX_MS));
}

/*
*Specify the unit for the pulse (5-25ms) with specific duration output to
*the servo pin: 0.1ms
*/
void servoWriteMS(int pin, int ms)
{
	if(ms > SERVO_MAX_MS)
	{
		ms = SERVO_MAX_MS;
	}
	if(ms < SERVO_MIN_MS)
	{
		ms = SERVO_MIN_MS;
	}

	softPwmWrite(pin, ms);
}

int main(void)
{
	int i;

	if(wiringPiSetup() == -1)
	{
		printf("wiringPi setup failed!");
		return 1;
	}

	printf("Program is starting...\n");

	servoInit(servoPin); //initialize the PWM pin to servo

	while(1)
	{
		//make servo rotate from minimum angle to maximum angle
		for(i = SERVO_MIN_MS; i < SERVO_MAX_MS; i++)
		{
			servoWriteMS(servoPin, i);
			delay(10);
		}

		delay(500);

		//make servo rotate from maximum angle to minimum angle
		for(i = SERVO_MAX_MS; i > SERVO_MIN_MS; i--)
		{
			servoWriteMS(servoPin, i);
			delay(10);
		}

		delay(500);

	}

	return 0;
}

