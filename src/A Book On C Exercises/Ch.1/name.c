/*
* @Author: Aaron Earl
* Note: Ex 8 Skipped, Windows
* disallows file with no extension to be run
* Solution to Ch.1 Ex. 11 from
* A Book On C
*
* Task:
* Write a program that asks interactively for your name and age and responds with
* Hello name, next year you will be next_age.
* where next_age is age + 1.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char name[99]; //Place to store the input name
    int age; //Variable for age

    printf("What is your name and age?: "); //Output
    scanf("%s", name); //Input name (name is already a pointer to char array)
    scanf("%d", &age); //Input age (use address to store value)
    printf("Hello %s, next year you will be %d", name, age + 1); //Output and arithmetic

    return 0;
}