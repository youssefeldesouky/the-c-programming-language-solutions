/** @file entab.c
 *  @brief Implementation for Exercise 1-21.
 *  
 *  Exercise 1-21. Write a program entab that replaces strings of blanks
 *  by the minimum number of tabs and blanks to achieve the same spacing.
 *  Use the same tab stops as for detab. When either a tab or a single blank
 *  would suffice to reach a tab stop, which should be given preference? 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

//Defines the length of a tab stop in blanks
//CAUTION! This has to be set to the same number of blanks used by the system,
//otherwise an incorrect output is to be expected.
#define TAB 8
//Defines the state of the the cursor, where IN defines being inside
//a series of blanks
enum {OUT, IN}; 

/** @brief A function that replaces strings of blanks with its equivalent
 *  tab stops (\t) and blanks.
 *  @return void
*/
void entab(void){
    int c;
    int idx = 0;
    unsigned char state = OUT;
    int blanks_count = 0;
    while((c=getchar()) != EOF){
        if(c == '\n'){
            putchar(c);
            idx = 0;
            blanks_count = 0;
        }
        else if(c == ' '){
            state = IN;
            blanks_count++;
        }
        else {
            if(state == IN){
                state = OUT;
                int tab_start = (idx / TAB) * TAB;
                int spaces = idx + blanks_count - tab_start;
                int tabs = (spaces) / TAB;
                int blanks = ((tabs > 0) ? (spaces) - (tabs * TAB) : blanks_count);
                for(int i = 0; i < tabs; putchar('\t'), i++);
                for(int i = 0; i < blanks; putchar(' '), i++);
                idx += blanks_count+1;
                blanks_count = 0;
            }else{
                idx++;
            }
            putchar(c);
        }
    }
}

//To signal an EOF in terminal, used CTRL-D
int main(void){
    entab();
    return 0;
}