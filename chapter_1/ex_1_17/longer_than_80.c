/** @file longer_than_80.c
 *  @brief Implementation for Exercise 1-17.
 *  
 *  Exercise 1-17. Write a program to print all input lines
 *  that are longer than 80 characters. 
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

/** @brief A function that only prints lines in stdin longer than 80 characters
 *  and their lengths.
 *  @return void
*/
void longer_than_80(void){
    char buf[MAXLEN] = "\0";
    size_t len;
    while((len=n_getline(buf, MAXLEN)) != 0){
        if(len > 80){
            printf("%s\t%ld\n", buf, len);
        }
    }
}

//To signal an EOF in terminal, used CTRL-D
int main(void){
    longer_than_80();
    return 0;
}