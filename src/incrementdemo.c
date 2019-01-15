/*
* @Author: Aaron Earl
* A Book On C
*
* Demonstration of important concept with
* increment order of operations.
*/

#include <stdio.h>

int main(void)
{
    int a, b, c = 0;

    a = ++c; //pre-increment
    b = c++; //post-increment
    printf("%d %d %d\n", a, b, ++c); //1 1 3 is printed
}