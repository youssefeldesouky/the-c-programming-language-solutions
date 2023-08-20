/** @file detab.c
 *  @brief Implementation for Exercise 1-20.
 *  
 *  Exercise 1-20. Write a program to print all input lines
 *  that are longer than 80 characters. 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

//Defines the length of a tab stop in blanks
#define TAB 5

/** @brief A function that replaces horizontal tabs (\t) with its equivalent
 *  user-defined number of blanks. 
 *  @return void
*/
void detab(void){
    int c;
    int idx = 0;
    while((c=getchar()) != EOF){
        if(c == '\n'){
            idx = 0;
            putchar(c);
        }
        else if(c == '\t'){
            int tabs = TAB - (idx % TAB);
            for(int i = 0; i < tabs; putchar(' '), ++i, ++idx);
        }
        else {
            putchar(c);
            idx++;
        }
    }
}

//To signal an EOF in terminal, used CTRL-D
int main(void){
    detab();
    return 0;
}