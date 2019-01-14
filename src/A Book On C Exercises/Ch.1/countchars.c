/*
* @Author: Aaron Earl
* Solution to Ch.1 Ex. 20 from
* A Book On C
*
* Task:
* In ANSI C the printf() function returns as an int the number of characters
* printed. To see how this works, write a program containing the following lines.
* What gets printed if the control string is replaced by
* "abc\nabc\n" or "abc\0abc\0"
*
* Result:
* First print count 7 characters. Each word and the space value.
* Second print counts 8 (includes the newline characters)
* Third print counts 3 chars. Counts until first termination character
*/

#include <stdio.h>

int main(void)
{
    int cnt;

    //cnt = printf("abc abc"); //First print
    //cnt = printf("abc\nabc\n"); //Second print
    cnt = printf("abc\0abc\0"); //Third print
    printf("\nNo. of characters printed: %d\n", cnt);

    return 0;
}