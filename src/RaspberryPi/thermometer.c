/*
*@Author: Aaron Earl
*5/30/19
*
*From Freenove RPi tutorials
*Ch.11 Thermistor
*
*Note: Cicuit is same from last
*lab sans LED and in place of
*photoresitor the thermistor 
*/

#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>
#include <math.h>

#define address 0x48	//pcf8591 default address
#define pinbase 64		//any number of 64
#define A0 pinbase + 0
#define A1 pinbase + 1
#define A2 pinbase + 2
#define A3 pinbase + 3

int main(void)
{
	int adcValue;
	float tempK, tempC;
	float voltage, Rt;

	if(wiringPiSetup() == -1)
	{
		printf("wiringPi setup failed!");
		return 1;
	}

	pcf8591Setup(pinbase, address);

	while(1)
	{
		adcValue = analogRead(A0);	//Read A0 pin
		voltage = (float)adcValue / 255.0 * 3.3; //Calculate voltage
		//Calculate resistance value of the thermistor
		Rt = 10 * voltage / (3.3 - voltage);
		//Calculate temperature (Kelvin)
		tempK = 1 / (1 / (273.15 + 25) + log(Rt/10) / 3950.0);
		//Calculate temperature (Celsius)
		tempC = tempK - 273.15;

		printf("ADC Value: %d, \tVoltage: %.2fV, \tTemperature: %.2fC\n",
		adcValue, voltage, tempC);
		delay(100);

	}

	return 0;
}
