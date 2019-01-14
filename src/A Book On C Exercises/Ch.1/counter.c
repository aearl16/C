/*
* @Author: Aaron Earl
* Solution to Ch.1 Ex. 19 from
* A Book On C
*
* Task:
* Put the following lines into a program and run it so that you understand its effects.
* What happens if you type the letter x when prompted by your program? What numbers
* can be printed by your program? Hint: If scanf() encounters an end-of-file
* mark before any conversions have occurred, then the value EOF is returned, where
* EOF is defined in stdio.h as a symbolic constant, typically with the value -1. You
* should be able to get your program to print this number.
*
* Result:
* Input numbers returns a count of the number of items.
* Input X returns count = 0, because the x wasn't
* succesfully converted to a decimal.
*/

#include <stdio.h>

int main(void)
{
    int a1, a2, a3, cnt;

    printf("Input three integers:  ");
    cnt = scanf("%d%d%d", &a1, &a2, &a3);
    printf("Number of successful conversions: %d\n", cnt);

    return 0;
}