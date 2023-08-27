/** @file vertical_histogram.c
 *  @brief Implementation for Exercise 1-14.
 *  
 *  Exercise 1-14. Write a program to print a histogram of the frequencies
 *  of different characters in its input.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

//Defines the number of letters.
#define CHARS 26U

/** @brief A function that counts the frequency of each character in the stdin file,
 *         then it draws a vertical histogram for all those frequencies.
 *  @return Void.
*/
void vertical_histogram(void)
{
    unsigned int alphapet[CHARS] = {0};
    int c = '\0';
    unsigned int max_len = 0;
    while((c = getchar()) != EOF)
    {
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            unsigned char idx = (c <= 'Z')?(c-'A'):(c-'a');
            alphapet[idx]++;
            max_len = (alphapet[idx] > max_len) ? alphapet[idx] : max_len;
        }
    }
    //Histogram Printing
    for(unsigned int i = 0; i < max_len; i++)
    {
        printf("%3d|  ", max_len - i);
        for(unsigned int j = 0; j < CHARS; j++)
        {
            if(alphapet[j] >= max_len - i)
            {
                putchar('*');
            }else
            {
                putchar(' ');
            }
            printf("  ");
        }
        putchar('\n');
    }
    printf("    ");
    for(unsigned int i = 0; i < CHARS * 3; i++)
    {
        putchar('_');
    }
    putchar('\n');
    printf("    ");
    for(unsigned int i = 0; i < CHARS; i++)
    {
        printf("%3c", i+'A');
    }
    putchar('\n');
}

//To signal an EOF in terminal, used CTRL-D
int main()
{
    vertical_histogram();
    return 0;
}