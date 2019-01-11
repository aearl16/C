/*
* @Author: Aaron Earl
* Solution to Ch.1 Ex. 12 from
* A Book On C
*
* Task:
* Write a program that neatly prints a table of powers.
*/

#include <stdio.h>
#include <math.h> //To use pow

int main(void)
{
    int i; //Counter Storage

    //Print Header, 12 to align with table header
    printf("%12s   A TABLE OF POWERS   :::::::\n", ":::::::");
    //Print header, allow enough space for integers
    printf("%12s%12s%12s%12s%12s\n", "Integer", "Square", "3rd Power", "4th Power", "5th Power");
    //Print header base bar
    printf("%12s%12s%12s%12s%12s\n", "-------", "------", "---------", "---------", "---------");
    
    //Count up and perform arithmetic
    for(i = 1; i <= 100; ++i)
    {
        printf("%12d%12.0f%12.0f%12.0f%12.0f\n", i, pow(i, 2), pow(i, 3), pow(i, 4), pow(i, 5));
    }

    return 0;
}