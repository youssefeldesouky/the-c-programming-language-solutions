/** @file replace_mblanks.c
 *  @brief Implementation for Exercise 1-9.
 *  
 *  Exercise 1-9. Write a program to copy its input to its output,
 *  replacing each string of one or more blanks by a single blank.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

/** @brief A function that replaces contageous blanks in the stdin
 *         file with a single blank.
 *  @return Void.
*/
void replace_mblanks(void)
{
    int c = '\0';
    int last_c = c;
    while((c = getchar()) != EOF)
    {
        if(c == ' ' && last_c == ' ')
        {
            continue;
        }
        last_c = c;
        putchar(c);
    }
}

//To signal an EOF in terminal, used CTRL-D
int main()
{
    replace_mblanks();
    return 0;
}