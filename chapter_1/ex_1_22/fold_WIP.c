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

/** @brief A function that only prints lines in stdin longer than 80 characters
 *  and their lengths.
 *  @return void
*/
void fold(void){
    int c = '\0', b_c = '\0', f_c = '\0';
    size_t i = 0;
    c = getchar();
    for(i = 1; (f_c=getchar()) != EOF; i++, b_c = c, c = f_c){
        if(i % (BREAK_POINT) == 0){
            //i = 0;
            if(isalpha(c)){
                if(isalpha(b_c)){
                    if(!isalpha(f_c)){
                        putchar(c);
                        putchar('\n');
                        continue;
                    }
                    putchar('-');
                }else{
                    putchar(' ');
                }
            }
            putchar('\n');
        }
        if(i % (BREAK_POINT) == 1 && c == ' ') {i--; continue;}
        putchar(c);
    }
}

//To signal an EOF in terminal, used CTRL-D
int main(void){
    fold();
    return 0;
}