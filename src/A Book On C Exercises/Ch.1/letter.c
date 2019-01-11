/*
* @Author: Aaron Earl
* Note: Ex 8 Skipped, Windows
* disallows file with no extension to be run
* Solution to Ch.1 Ex. 9 from
* A Book On C
*
* Task:
* The following program writes a large letter Ion the screen:
* Compile and run this program so that you understand its effect. Write a similar
* program that prints a large letter C on the screen.
*
* To make my simple C I just moved the spacing from
* the original program and added more Is on the top and
* bottom. Also I removed some top and bottom space
* from the original program. I didn't need that much
* space.
*/

#include <stdio.h>

#define BOTTOM_SPACE "\n\n"
#define HEIGHT       17
#define OFFSET       "                 " //17 Blanks
#define TOP_SPACE    "\n\n"

int main(void)
{
    //Make the I
    int i;

    printf(TOP_SPACE);
    printf(OFFSET "IIIIIII\n");
    for(i = 0; i < HEIGHT; ++i)
    {
        printf(OFFSET "  III\n");
    }
    printf(OFFSET "IIIIIII\n");
    printf(BOTTOM_SPACE);
    
    //Make a C
    int j;

    printf(TOP_SPACE);
    printf(OFFSET "IIIIIIIIIIII\n");
    for(j = 0; j < HEIGHT; ++j)
    {
        printf(OFFSET "III\n");
    }
    printf(OFFSET "IIIIIIIIIIII\n");
    printf(BOTTOM_SPACE);

    return 0;
}