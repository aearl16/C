/*
*@Author: Aaron Earl
* 5/27/19
*
*From Freenove RPi tutorials
*Ch.8 Potentiometer and LED
*
* Note: Pin arrangement is similar
* from previous lab. Only change is
* AOUT is not connected the the 220Ohm
* resistor and LED. Intead LED and resistor
* are connected to GPIO17
*/

#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>
#include <softPwm.h>

#define address 0x48	//pcf8591 default address
#define pinbase 64		//any number above 64
#define A0 pinbase + 0
#define A1 pinbase + 1
#define A2 pinbase + 2
#define A3 pinbase + 3
#define ledPin 0

int main(void)
{
	int value;
	float voltage;

	if(wiringPiSetup() == -1)
	{
		printf("wiringPi setup failed!");
		return 1;
	}

	softPwmCreate(ledPin, 0, 100);
	pcf8591Setup(pinbase, address);

	while(1)
	{
		value = analogRead(A0); //read A0 pin
		softPwmWrite(ledPin, value * 100 / 255);
		voltage = (float)value / 255.0 * 3.3; //calculate voltage
		printf("ADC value: %d, \tVoltage: %.2fV\n", value, voltage);
	}

	return 0;
}
