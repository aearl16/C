/*
* @Author: Aaron Earl
* My solution to Ch.1 Exercises from
* A Book On C
*
* Task:
* On the screen write the words
* she sells sea shells by the seashore
* (a) all on one line, (b) on three lines, (c) inside a box.
*/

#include <stdio.h>

int main(void)
{
    //a.) one line
    printf("%s\n\n", "she sells sea shells by the seashore");

    //b.) on three lines
    printf("%s\n%s\n%s\n\n", "she sells", "sea shells by", "the seashore");

    //c.) inside a box
    printf("%40s\n%40s\n%40s\n\n" , "----------------------------------------", 
    "| she sells sea shells by the seashore |", 
    "----------------------------------------");

    return 0;
}