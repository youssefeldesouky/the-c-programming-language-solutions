/** @file horizontal_histogram.c
 *  @brief Implementation for Exercise 1-13.
 *  
 *  Exercise 1-13. Write a program to print a histogram of the lengths
 *  of words in its input. It is easy to draw the histogram with the bars
 *  horizontal; a vertical orientation is more challenging. 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

// Defines the maximum word Length to be counted. 
#define MAXLEN 10

/** @brief A function that counts the lengths of each word in the stdin file,
 *         then it draws a horizontal histogram for all those lengths.
 *  @return Void.
*/
void horizontal_histogram(void)
{
    int lens[MAXLEN] = {0};
    char state = 0;
    int c = '\0';
    unsigned int len = 0;
    while((c = getchar()) != EOF)
    {
        if(c == '\n' || c == ' ' || c == '\t')
        {
            if(state == 1)
            {
                state = 0;
                if(len < MAXLEN) lens[len-1]++;
                len = 0;
            }
        }
        else
        {
            state = 1;
            len++;
        }
    }
    for(int i = 0; i < MAXLEN; i++)
    {
        printf("%2d| ", i+1);
        for(int j = 0; j < lens[i]; putchar('*'), j++);
        putchar('\n');
    }
}

//To signal an EOF in terminal, used CTRL-D
int main()
{
    horizontal_histogram();
    return 0;
}