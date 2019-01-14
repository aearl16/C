/*
* @Author: Aaron Earl
* Note: Ex 14 skipped
* Solution to Ch.1 Ex. 15 from
* A Book On C
*
* Task:
* Run this program so that you understand its effects. Note that the better algorithm
* for computing the average is embodied in the line
* avg += (x avg) / i;
* Explain why this algorithm does, in fact, compute the running average. Hint: Do
* some simple hand calculations first.
*
* Result:
* Code may be missing some lines. Initial printout works,
* but no numbers are printed.
* What it should do is print the average of the remaining,
* numbers in the list, hence the (x - avg)
*/

#include <stdio.h>

int main(void)
{
    int i;
    double x;
    double avg = 0.0; //a better average
    double navg;      //a naive average
    double sum = 0.0;

    printf("%5s%17s%17s%17s\n%5s%17s%17s%17s\n\n",
    "Count", "Item", "Average", "Naive avg", 
    "-----", "----", "-------", "------");

    for (i = 1; scanf("%lf", &x) == 1; ++i)
    {
        avg += (x - avg) / i;
        sum += x;
        navg = sum / i;
        printf("%5d%17e%17e%17e\n", i, x, avg, navg);
    }

    return 0;
}