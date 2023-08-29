/** @file loop.c
 *  @brief Implementation for Exercise 2-2.
 * 
 *  Write a loop equivalent to the for loop above without using && or ||. 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

//Defines the maximum length of a line
#define MAXLEN 1000

/** @brief A function that moves a line from stdin to a buffer
 *  @param s The string buffer that will contain the captured line
 *  @param lim The maximum length of a line including the Null Terminator
 *  @return void
*/
void get_line(char s[], size_t lim){
    int c = '\0';
    size_t i = 0;
    for (i=0; i < lim - 1; ++i){
        if((c=getchar()) != EOF){
            if(c != '\n'){
                s[i] = c; 
            }
        }
    }
    s[i] = '\0';
}

//To signal an EOF in terminal, used CTRL-D
int main(void){
    char buf[MAXLEN];
    get_line(buf, MAXLEN);
    puts(buf);
    return 0;
}