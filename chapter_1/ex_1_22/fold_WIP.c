/** @file fold.c
 *  @brief Implementation for Exercise 1-22.
 *  
 *  Exercise 1-22. Write a program to ``fold'' long input lines 
 *  into two or more shorter lines after the last non-blank character
 *  that occurs before the n-th column of input. Make sure your program 
 *  does something intelligent with very long lines, and if there are no
 *  blanks or tabs before the specified column.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <ctype.h>

//Defines the maximum length of line before folding it
#define BREAK_POINT 40

int get_word(char *buffer, size_t n){
    int c = 0, i = 0;
    while((c = getchar()) != EOF){
        if(isspace(c) || i >= n){
            break;
        }
        buffer[i++] = (char)c;
    }
    buffer[i] = '\0';
    if(i > 0) return i;
    if(c == EOF) return EOF;
    return 0;
}

/** @brief A function that folds long string lines into multiple lines of size BREAK_POINT
 *  @return void
*/
void fold(void){
    int b_c = 0, c = 0;
    int index = 0;
    while((c = getchar()) != EOF){
        putchar(c);
        index++;
        if(index >= BREAK_POINT){
            putchar('\n');
            index = 0;
        }
        b_c = c;
    }
}

//To signal an EOF in terminal, used CTRL-D
int main(void){
    int size = 0;
    char buf[100];
    int i = 0;
    while((size = get_word(buf, 100)) != EOF){
        printf("%d: %s\t%d\n", size, buf, i++);
        
    }
    //fold();
    return 0;
}

void foffffld(void)
{
    int c = '\0', b_c = '\0', f_c = '\0';
    size_t i = 0;
    c = getchar();
    for (i = 1; (f_c = getchar()) != EOF; i++, b_c = c, c = f_c)
    {
        if (i % (BREAK_POINT) == 0)
        {
            // i = 0;
            if (isalpha(c))
            {
                if (isalpha(b_c))
                {
                    if (!isalpha(f_c))
                    {
                        putchar(c);
                        putchar('\n');
                        continue;
                    }
                    putchar('-');
                }
                else
                {
                    putchar(' ');
                }
            }
            putchar('\n');
        }
        if (i % (BREAK_POINT) == 1 && c == ' ')
        {
            i--;
            continue;
        }
        putchar(c);
    }
}