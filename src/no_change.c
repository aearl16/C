//@Author: Aaron Earl
/*
* Demonstration of important C concept of passing by value.
* Original program from A Book on C Ch 1.8
*/

#include <stdio.h>

//Main
int main(void)
{
    int a = 1;
    void try_to_change_it(int);

    //1 is printed
    printf("%d\n" , a);
    try_to_change_it(a);
    /*
    * 1 is printed again because value is passed by value
    * and not by reference, which would require the use of the address operator
    */ 
    printf("%d\n" , a);
    return 0;
}

void try_to_change_it(int a)
{
    a = 777;
}