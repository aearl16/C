/*
* @Author: Aaron Earl
* Solution to Ch.1 Ex. 10 from
* A Book On C
*
* Task:
* Take a working program and omit each line in turn and run it through the compiler.
* Record the error messages each such deletion causes. As an example, consider the
* following code in the file nonsense.c:
*
* Result:
* 1.) Comment out include:
* nonsense.c: In function 'main':
* nonsense.c:20:5: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
*      printf("nonsense\n");
*      ^~~~~~
* nonsense.c:20:5: warning: incompatible implicit declaration of built-in function 'printf'
* nonsense.c:20:5: note: include '<stdio.h>' or provide a declaration of 'printf'
*
* 2.) Comment out main:
* nonsense.c:29:1: error: expected identifier or '(' before '{' token
* {
*
* 3.) Comment out starting bracket:
* nonsense.c: In function 'main':
* nonsense.c:33:5: error: expected declaration specifiers before 'printf'
*      printf("nonsense\n");
*      ^~~~~~
* nonsense.c:34:1: error: expected declaration specifiers before '}' token
* }
* ^
* nonsense.c:34:1: error: expected '{' at end of input
*
* 4.) Comment out print statement:
* No message ==> esentially empty program with no function
*
* 5.) Comment out ending bracket:
* nonsense.c: In function 'main':
* nonsense.c:47:5: error: expected declaration or statement at end of input
*     printf("nonsense\n");
*     ^~~~~~
*/

#include <stdio.h>

void main(void)
{
    printf("nonsense\n");
}