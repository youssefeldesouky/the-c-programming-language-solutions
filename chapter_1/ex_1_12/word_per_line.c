/** @file word_per_line.c
 *  @brief Implementation for Exercise 1-12.
 *  
 *  Exercise 1-12. Write a program that prints its input one word per line.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

/** @brief A function that takes input from the stdin file,
 *         then it prints each word on a separate line.
 *  @return Void.
*/
void word_per_line(void)
{
    char state = 0;
    int c = '\0';
    while((c = getchar()) != EOF)
    {
        if(c == '\n' || c == ' ' || c == '\t')
        {
            if(state == 1) state = 0, puts("");
        }
        else
        {
            state = 1;
            putchar(c);
        }
    }
}

//To signal an EOF in terminal, used CTRL-D
int main()
{
    word_per_line();
    return 0;
}