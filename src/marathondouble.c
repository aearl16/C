/*
* @Author: Aaron Earl
* Solution to Ch.1 Ex. 3 from
* A Book On C
*
* Task:
* Write a version of the marathon program in Section 1.3, "Variables, Expressions,
* and Assignment," on page 11, in which all constants and variables are of type doub1e. 
* Is the output of the program exactly the same as that of the original program?
*/

/*
* The result:
*  Integer: A marathon is 41.834000 kilometers.
*
* Original: A marathon is 42.185970 kilometers.
* 
* Double: A marathon is 42.185969 kilometers.
*/

#include <stdio.h>

int main(void)
{
    double  miles, yards;
    double kilometers;

    miles = 26;
    yards = 385;
    kilometers = 1.609 * (miles + yards / 1760.0);
    printf("\nA marathon is %f kilometers.\n\n", kilometers);

    return 0;
}

