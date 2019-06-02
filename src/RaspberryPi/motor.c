/*
*@Author: Aaron Earl
*6/1/19
*
*From Freenove RPi tutorials
*Ch.13 Motor and Driver
*
*Note: Circuit similar from last lab.
*AIN0 connected to 10k potentiometer.
*Analog value is read to control motor.
*Motor is connected to L293D driver.
*Driver pins connected to GPIO17,27,22.
*/

#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>
#include <softPwm.h>
#include <math.h>
#include <stdlib.h>

#define address 0x48 //pcf8591 default address
#define pinbase	64   //any number above 64
#define A0 pinbase + 0
#define A1 pinbase + 1
#define A2 pinbase + 2
#define A3 pinbase + 3
//Define the pins connected to the L293D IC
#define motorPin1 2
#define motorPin2 0
#define enablePin 3

//Map function: map the value from a range of mapping to another range.
//Note: This function was not sufficiently explaned in the tutorials
long map(long value, long fromLow, long fromHigh, long toLow, long toHigh)
{
	return (toHigh-toLow)*(value-fromLow) / (fromHigh-fromLow) + toLow;
}

/*
*Motor function: determine the direction and speed of the motor 
*according to the ADC
*/
void motor(int ADC)
{
	int value = ADC - 128;

	if(value > 0)
	{
		digitalWrite(motorPin1, HIGH);
		digitalWrite(motorPin2, LOW);
		printf("turn Forward...\n");
	}
	else if(value < 0)
	{
		digitalWrite(motorPin1, LOW);
		digitalWrite(motorPin2, HIGH);
		printf("turn Backwards...\n");
	}
	else //Potentiometer in the center position
	{
		digitalWrite(motorPin1, LOW);
		digitalWrite(motorPin2, LOW);
		printf("Motor Stop...\n");
	}

	softPwmWrite(enablePin, map(abs(value), 0, 128, 0, 255));
	//Print the PWM duty cycle
	printf("The PWM duty cycle is %d%%\n", abs(value) * 100 / 127);

}

int main(void)
{
	int value;

	if(wiringPiSetup() == -1)
	{
		printf("wiringPi setup failed!");
		return 1;
	}

	pinMode(enablePin, OUTPUT); //set mode for enable pin
	pinMode(motorPin1, OUTPUT);
	pinMode(motorPin2, OUTPUT);
	softPwmCreate(enablePin, 0, 100); //define PWM pin

	pcf8591Setup(pinbase, address); //initialize pcf8591

	while(1)
	{
		value = analogRead(A0); //read A0 pin
		printf("ADC Value: %d\n", value);
		motor(value); //start the motor
		delay(100);
	}

	return 0;
}
