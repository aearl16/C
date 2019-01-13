/*
* @Author: Aaron Earl
* Solution to Ch.1 Ex. 13 from
* A Book On C
*
* Task:
* Try the Code below. Is the compiler happy? It should be.
* 
* Result:
* Compiler does not complain and program runs
*/

int main(void)
{
    int i;

    for(i = 0; i < 3 ; ++i)
    {} //No semicolon
    for(i = 0; i < 3; ++i)
    { ; ; ; } //Three semicolons but none after the statement
}