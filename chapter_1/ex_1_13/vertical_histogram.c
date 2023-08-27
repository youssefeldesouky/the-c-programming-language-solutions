/** @file vertical_histogram.c
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

//Defines the maximum word Length to be counted.
#define MAXLEN 10U

/** @brief A function that counts the lengths of each word in the stdin file,
 *         then it draws a vertical histogram for all those lengths.
 *  @return Void.
*/
void vertical_histogram(void)
{
    unsigned int lens[MAXLEN] = {0};
    char state = 0;
    int c = '\0';
    unsigned int len = 0, max_len = 0;
    while((c = getchar()) != EOF)
    {
        if(c == '\n' || c == ' ' || c == '\t')
        {
            if(state == 1)
            {
                state = 0;
                if(len < MAXLEN)
                {
                    lens[len-1]++;
                    max_len = (lens[len-1] > max_len) ? lens[len-1] : max_len;
                }
                len = 0;
            }
        }
        else
        {
            state = 1;
            len++;
        }
    }
    //Histogram Printing
    for(unsigned int i = 0; i < max_len; i++)
    {
        printf("%3d|  ", max_len - i);
        for(unsigned int j = 0; j < MAXLEN; j++)
        {
            if(lens[j] >= max_len - i)
            {
                putchar('*');
            }
            else
            {
                putchar(' ');
            }
            printf("  ");
        }
        putchar('\n');
    }
    printf("    ");
    for(unsigned int i = 0; i < MAXLEN * 3; i++)
    {
        putchar('_');
    }
    putchar('\n');
    printf("    ");
    for(unsigned int i = 0; i < MAXLEN; i++)
    {
        printf("%3d", i+1);
    }
    putchar('\n');
}

//To signal an EOF in terminal, used CTRL-D
int main()
{
    vertical_histogram();
    return 0;
}