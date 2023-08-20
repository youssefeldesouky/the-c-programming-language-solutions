/** @file rtrim.c
 *  @brief Implementation for Exercise 1-18.
 *  
 *  Exercise 1-18. Write a program to remove trailing blanks 
 *  and tabs from each line of input, and to delete entirely blank lines. 
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
void rtrim(void){
    char buf[MAXLEN] = "\0";
    size_t len;
    int i;
    while((len=n_getline(buf, MAXLEN)) != 0){
        for(i = len - 1; i >= 0; i--){
            if(buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\n') buf[i] = '\0';
            else break;
        }
        printf((buf[0] == 0)?"%s":"%s\n", buf);
    }
}

//To signal an EOF in terminal, used CTRL-D
int main(void){
    rtrim();
    return 0;
}