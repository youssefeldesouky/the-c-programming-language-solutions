/** @file longest_line.c
 *  @brief Implementation for Exercise 1-16.
 *  
 *  Exercise 1-16. Revise the main routine of the longest-line program
 *  so it will correctly print the length of arbitrary long input lines
 *  and as much as possible of the text. 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

//Defines the maximum length of a line
#define MAXLEN 1000

/** @brief Copies characters between character arrays up to a maxmimum length 
 *  @param dest The Destination (Copied to) Array
 *  @param src The Source (Copied from) Array
 *  @param len The maximum Length of a string
 *  @return void
*/
void copy_str(char dest[], char src[], size_t len){
    for(size_t i = 0; i < len && src[i] != '\0'; i++){
        dest[i] = src[i];
    }
}

/** @brief A function that moves a line from stdin to a buffer while keeping track
 *         of its length
 *  @param buf The string buffer that will contain the captured line
 *  @param len The maximum length of a line
 *  @return The length of the captured line.
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

/** @brief A function that reads the input in stdin, then prints
 *         the longest line that is less than a predefined maximum
 *         length, alongside its length.
 *  @return void
*/
void longest_line(void){
    char buf[MAXLEN] = "\0";
    char maxline[MAXLEN] = "\0";
    size_t len;
    size_t max = 0;
    while((len=n_getline(buf, MAXLEN)) != 0){
        if(len >= max){
            max = len;
            copy_str(maxline, buf, MAXLEN);
        }
    }
    if(max > 0) printf("%s\t%ld\n", maxline, max);
    else puts("No text was found");
}

//To signal an EOF in terminal, used CTRL-D
int main(){
    longest_line();
    return 0;
}