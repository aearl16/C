/*
* @Author: Aaron Earl
* Solution to Ch.1 Ex. 4 from
* A Book On C
*
* Task:
* Take one of your working programs and alter it by deleting the keyword void in the
* line:
*   int main(void)
* When you compile your program, does your compiler complain? ~robab~y not. (See
* Section 5.3, "Function Prototypes," on page 202, for further dIscussIOn.) .Next,
* remove the keyword vo; d and remove the following line from the body of main:
*   return 0;
*/

/*
* The result:
* Doesn't complain deleting void
* Doesn't complain deleting return 0;
* 
* Elevate warninng level:
* Usually the -Wall command turns on all warnings at compile
* time. For some reason program doesn't complain that it has no
* return value.
*/

#include <stdio.h>

int main()
{
    double  miles, yards;
    double kilometers;

    miles = 26;
    yards = 385;
    kilometers = 1.609 * (miles + yards / 1760.0);
    printf("\nA marathon is %f kilometers.\n\n", kilometers);
}

