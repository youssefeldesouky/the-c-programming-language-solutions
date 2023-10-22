/** @file case.c
 *  @brief Implementation for Exercise 7-1.
 *
 *  Write a program that converts upper case to lower or lower case
 *  to upper, depending on the name it is invoked with, as found in argv[0].
 *
 *  @author Youssef Samir
 *  @bug No Known Bugs.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/** @brief A function that takes a string determining the case 
 *         to set the input found in stdin, then print it.
 *  @param type "lower" to set stdin to lowercase, "upper" to set it to uppercase, otherwise print it as is.
 *  @return void.
 */
void io_case(char *type){
    int c = '\0';
    while((c = getchar()) != EOF){
        if(!strcmp(type, "lower")){
            c = tolower(c);
        }else if(!strcmp(type, "upper")){
            c = toupper(c);
        }
        putchar(c);
    }
}

// Set argv[1] to either "lower" or "upper", otherwise 
// the characters will be printed in their original case
// To signal an EOF in terminal, used CTRL-D
int main(int argc, char **argv){
    if(argc > 1){
        io_case(argv[1]);
    }
    return 0;
}
