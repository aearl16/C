/*
* @Author: Aaron Earl
* 5/27/19
*
* From Freenove RPi tutorials
* Ch.7 AD/DA Converter
*
* Task: convert analog voltage to digital
* output voltage
*
* Note: My kit came with PCF8591T IC Chip
*
* Pin Notes: the IC diagram wasn't very clear so
* I've wrote out the pin values as follows;
*
* Left Pins
* AIN0: Potentiometer pin3 input
* AIN1: No input
* AIN2: No input
* AIN3: No input
* A0: GND
* A1: GND
* A2: GND
* VSS: GND
*
* Right Pins
* VDD: +3.3V
* AOUT: 220OHM Resistor to LED
* VREF: +3.3V
* AGND: GND
* EXT: GND
* OSC: No input/output
* SCL: SCL1(Board)
* SDA: SDA1(Board)
*/

#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>

#define address 0x48	// PCF8591 default address
#define pinbase 64		// any number above 64
#define A0 pinbase + 0
#define A1 pinbase + 1
#define A2 pinbase + 2
#define A3 pinbase + 3

int main(void)
{
	int value;
	float voltage;

	//Fisrt stage warning missing from code
	if(wiringPiSetup() == -1)
	{
		printf("wiringPi setup failed!");
		return 1;
	}

	pcf8591Setup(pinbase, address);

	while(1)
	{
		value = analogRead(A0);	//Read A0 pin
		analogWrite(pinbase + 0, value);
		voltage = (float)value / 255.0 * 3.3;	//Calculate Voltage
		printf("ADC Value: %d, \tVoltage: %.2fV\n", value, voltage);
		delay(100);
	}

	return 0;
}
