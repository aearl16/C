/*
* @Author: Aaron Earl
* Solution to Ch.1 Ex. 5 from
* A Book On C
*
* Task:
* The following program may have a run-time error in it:
* Check to see that the program compiles without any error messages. Run the program
* to see the effect of integer division by zero. On most systems this program
* will exhibit a run-time error. If this happens on your system, try to rewrite the program
* without the variable y, but keep the error in the program. That is, divide by
* zero directly. Now what happens?
*/

/*
* The Result:
* First run no errors. No Printout either
* Try -Wall on compiler. No Errors
* Changing to 0 directly had no effect
*/

#include <stdio.h>

int main(void)
{
    int x, y = 0;
    x = 1 / y;
    printf("x = %d\n", x);
    return 0;
}