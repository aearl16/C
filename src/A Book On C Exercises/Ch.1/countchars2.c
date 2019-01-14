/*
* @Author: Aaron Earl
* Solution to Ch.1 Ex. 21 from
* A Book On C
*
* Task:
* In the previous exercise you were able to get different numbers printed, depending
* on the input you provided. Put the following lines into a program.
* By varying the input, what numbers can you cause to be printed? Hint: The numbers
* printed by the program you wrote for exercise 19, on page 66, can be printed here,
* but you have to work much harder to do it.
* 
* Result:
* I varied the input with \0, blanks, other letters, and EOF(-1),
* only got 3 to be printed each time.
*/

#include <stdio.h>

int main(void)
{
    char c1, c2, c3;
    int cnt;

    printf("Input three characters:  ");
    cnt = scanf("%c%c%c", &c1, &c2, &c3);
    printf("Number of successful conversions: %d\n", cnt);

    return 0;
}