/*
* @Author: Aaron Earl
* Solution to Ch.1 Ex. 6 from
* A Book On C
*
* Task:
* Most C systems provide for logically infinite floating values. Modify the program
* given in the previous by changing i nt to doub 1 e and, in the p ri ntf 0 statement,
* %d to %f. Does the program still exhibit a run-time error? On most systems the
* answer is no. What happens on your system?
*/

/*
* The Result:
* x = 1.#INF00
*/

#include <stdio.h>

int main(void)
{
    double x, y = 0;
    x = 1 / y;
    printf("x = %f\n", x);
    return 0;
}