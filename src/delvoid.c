/*
* @Author: Aaron Earl
* Solution to Ch.1 Ex. 4 from
* A Book On C
*
* Task:
* Write a version of the marathon program in Section 1.3, "Variables, Expressions,
* and Assignment," on page 11, in which all constants and variables are of type doub1e. 
* Is the output of the program exactly the same as that of the original program?
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

