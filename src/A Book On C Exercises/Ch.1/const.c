/*
* @Author: Aaron Earl
* Note: Ex 17 skipped due to pgm not working
* Solution to Ch.1 Ex. 18 from
* A Book On C
*
* Task:
* Experiment with the type qualifier const. How does your compiler treat the following
* code?
*
* Result:
* Compiler complains ==> assignment of read-only variable 'a'
*/

#include <stdio.h>

int main(void)
{
    const int a = 0;

    a = 333;
    printf("%d\n", a);
}