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
*/

#include <stdio.h>
#include <string.h>

#define MAXSTRING 100

void prn_string(char *);

int main(void)
{
    char s1[MAXSTRING], s2[MAXSTRING];

    strcpy(s1, "Mary, Mary, quite contrary, \n");
    strcpy(s2, "how does our garden grow?\n");
    prn_string(s1);
    prn_string(s2);
    strcat(s1, s2);
    prn_string(s1);

    return 0;
}

//Uses function putchar to print instead of printf
void prn_string(char *s)
{
    int i;

    for(i = 0; s[i] != '\0'; ++i)
    {
        putchar(s[i]);
    }
}