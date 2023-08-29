/** @file lower.c
 *  @brief Implementation for Exercise 2-10.
 * 
 *  Rewrite the function lower, which converts upper case
 *  letters to lower case, with a conditional expression instead of if-else. 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <stdlib.h>

/** @brief A function that converts an uppercase letter to its lowercase form.
 *  @param c The letter to be converted.
 *  @return The lowercase letter.
*/
char lower(char c){
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

//Enter the arguments in that order: c.
int main(int argc, char ** argv){
    if(argc > 1){
        char c = argv[1][0];

        printf("%c\n", lower(c));
    }
    return 0;
}