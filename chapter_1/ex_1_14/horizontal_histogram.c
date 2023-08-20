/** @file horizontal_histogram.c
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
#define CHARS 26

/** @brief A function that counts the frequency of each character in the stdin file,
 *         then it draws a horizontal histogram for all those frequencies.
 *  @return Void.
*/
void horizontal_histogram(void)
{
    int alphapet[CHARS] = {0};
    int c = '\0';
    unsigned int len = 0;
    while((c = getchar()) != EOF)
    {
        if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
        {
            alphapet[(c <= 'Z')?(c-'A'):(c-'a')]++;
        }
    }
    for(int i = 0; i < CHARS; i++)
    {
        printf("%2c| ", i+'A');
        for(int j = 0; j < alphapet[i]; putchar('*'), j++);
        putchar('\n');
    }
}

//To signal an EOF in terminal, used CTRL-D
int main()
{
    horizontal_histogram();
    return 0;
}