/*
*@Author: Aaron Earl
* Tutorial from Freenove RPi Pak
*
*Task: make an LED blink
* LED connected to GPIO17 
*/

#include <wiringPi.h>
#include <stdio.h>

#define ledPin 0

int main(void)
{
    if(wiringPiSetup() == -1)
    {
        printf("setup wiringPi failed!");
        return 1;
    }

    //When wiring is sucessfully initialized, print message to the screen
    printf("wiringPi initialized successfully, GPIO %d(wiringPi pin)\n", ledPin);

    pinMode(ledPin, OUTPUT);

    while(1)
    {
        digitalWrite(ledPin, HIGH); //LED On
        printf("LED On...\n");
        delay(1000);
	digitalWrite(ledPin, LOW); //LED Off
	printf("...LED Off\n");
	delay(1000);
    }

    return 0;
}
