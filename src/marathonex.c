/*
* @Author: Aaron Earl
* Solution to Ch.1 Ex. 2 from
* A Book On C
*
* Task:
* Use a hand calculator to verify that the output of the marathon program is correct.
* Create another version of the program by changing the floating constant 1760.0 to
* an integer constant 1760. Compile and execute the program and notice that the output
* is not the same as before. This is because integer division discards any fractional
* part.
*/

/*
* The result:
* A marathon is 41.834000 kilometers.
*
* A marathon is 42.185970 kilometers.
*/

#include <stdio.h>

int main(void)
{
    int  miles, yards;
    float kilometers;

    miles = 26;
    yards = 385;
    kilometers = 1.609 * (miles + yards / 1760.0);
    printf("\nA marathon is %f kilometers.\n\n", kilometers);

    return 0;
}

