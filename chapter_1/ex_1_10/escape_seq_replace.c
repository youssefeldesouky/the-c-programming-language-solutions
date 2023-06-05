/** @file escape_seq_replace.c
 *  @brief Implementation for Exercise 1-10.
 *  
 *  Exercise 1-10. Write a program to copy its input to its output,
 *  replacing each tab by \t, each backspace by \b, and each backslash by \\.
 *  This makes tabs and backspaces visible in an unambiguous way.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

/** @brief A function that replaces tabs, backspaces and backslashes,
 *         in the stdin filewith their literal esacape sequences.
 *  @return Void.
*/
void escape_seq_replace(void)
{
    int c = '\0';
    while((c = getchar()) != EOF){
        switch(c){
            case '\t':
                printf("\\t");
                break;
            case '\b':
                printf("\\b");
                break;
            case '\\':
                printf("\\\\");
                break;
            default:
                putchar(c);
        }
    }
}

//To signal an EOF in terminal, used CTRL-D
int main()
{
    escape_seq_replace();
    return 0;
}