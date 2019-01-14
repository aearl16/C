/*
* @Author: Aaron Earl
* Solution to Ch.1 Ex. 25 from
* A Book On C
*
* Task:
* Complete the following program by writing a prn_string() function that uses
* putchar() to print a string passed as an argument. Remember that strings are terminated
* by the null character \0. The program uses the strcatO function from
* the standard library. Its function prototype is given in the header file string.h. The
* function takes two strings as arguments. It concatenates the two strings and puts
* the results in the first argument.
*
* Note on Windows Ctrl->D is not EOF. Ctrl->Z and Return is.
* Also there is no infile option only outfile >.
*/

#include <stdio.h>

int main(void)
{
    char c;

    while (scanf("%c", &c) == 1)
    {
        printf("%c", c);
        printf("%c", c);
    }

    return 0;
}