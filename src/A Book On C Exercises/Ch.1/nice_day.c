/*
* @Author: Aaron Earl
* Solution to Ch.1 Ex. 22 from
* A Book On C
*
* Task:
* Use the ideas presented in the nice_day program in Section 1.8, "Arrays, Strings,
* and Pointers", on page 39, to The a program that counts the total number of letters.
* Use redirection to test your program. If infile is a file containing text, then the
* command
*  nletters < infile
* should cause something like
* Number of letters: 179
* to be printed on the screen.
*
* Note: Could figure out file re-direction on Windows.
* process seems more complicated than Linux/Unix
*/

#include <stdio.h>
#include <ctype.h>

#define MAXSTRING 100

int main(void)
{
    char c, name[MAXSTRING];
    int i, sum = 0, count;

    printf("\nHi! What is your name? ");
    for(i = 0; (c = getchar()) != '\n'; ++i)
    {
        name[i] = c;
        if (isalpha(c))
        {
            sum += c;
            ++count; //Count letters
        }
    }
    name[i] = '\0';
    printf("\n%s%s%s\n%s",
    "Nice to meet you ", name, ".",
    "Your name spelled backwards is ");
    for(--i; i >= 0; --i)
    {
        putchar(name[i]);
    }
    printf("\n%s%d%s\n",
    "and the letters in your name sum to ", sum, ".");
    printf("\n%s%d\n\n%s\n", "The number of letters in your name: ", count,
    "Have a nice day!");

    return 0;
}