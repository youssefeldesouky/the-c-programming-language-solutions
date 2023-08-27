/** @file syntax.c
 *  @brief Implementation for Exercise 1-24.
 * 
 *  Write a program to check a C program for rudimentary syntax errors like 
 *  unmatched parentheses, brackets and braces. Don't forget about quotes, 
 *  both single and double, escape sequences, and comments.
 *  (This program is hard if you do it in full generality.) 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

//Defines the maximum length of a line
#define MAXLEN 1000

/** @brief A function that moves a line from stdin to a buffer while keeping track
 *         of its length
 *  @param buf The string buffer that will contain the captured line
 *  @param len The maximum length of a line
 *  @return The length of the captured line
*/
int n_getline(char buf[], size_t len){
    int c = '\0';
    size_t i = 0;
    for(i = 0; i <= len && (c = getchar()) != EOF; i++){
        if(c == '\n'){
            break;
        }
        buf[i] = c;
    }
    buf[i] = '\0';
    if(c == EOF) return 0;
    return i;
}

/** @brief A function that removes trailing blanks and tabs from
 *  each line in stdin, and delete empty lines.
 *  @return void
*/
void syntax(void){
    char buf[MAXLEN] = "\0";
    size_t len = 1;
    int i = 0;
    for(i = 0; len != 0; i++){
        len = n_getline(buf, MAXLEN);
        puts(buf);
    }

}

//To signal an EOF in terminal, used CTRL-D
//To feed the file into the program, use redirection, i.e. "./a.out < file.c"
int main(void){
    syntax();
    return 0;
}