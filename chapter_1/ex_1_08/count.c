/** @file count.c
 *  @brief Implementation for Exercise 1-8.
 *  
 *  Exercise 1-8. Write a program to count blanks, tabs, and newlines.
 *  Applied to the stdin file.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

/** @brief A function that counts the number of blanks, tabs and newlines
 *        in the stdin file.
 *  @return Void.
*/
void count(void)
{
    unsigned int blanks = 0, tabs = 0, newlines = 0;
    int c = '\0';
    while((c = getchar()) != EOF)
    {
        switch(c)
        {
            case ' ':
                blanks++;
                break;
            case '\t':
                tabs++;
                break;
            case '\n':
                newlines++;
                break;
        }
    }
    printf("Blanks: %u\tTabs: %u\t\tNewLines: %u\n", blanks, tabs, newlines);
}

//To signal an EOF in terminal, used CTRL-D
int main()
{
    count();
    return 0;
}