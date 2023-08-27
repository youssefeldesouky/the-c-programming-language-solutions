/** @file reverse.c
 *  @brief Implementation for Exercise 1-19.
 *  
 *  Exercise 1-19. Write a function reverse(s) that reverses the character string s.
 *  Use it to write a program that reverses its input a line at a time.
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

/** @brief A function that reverses lines of string literals
 *  @param src The string buffer that will contain the line to be reversed
 *  @param len The length of the line
 *  @return void
*/
void reverse(char src[], size_t len){
    char tmp[len];
    copy_str(tmp, src, len);
    for(size_t i = 0; i < len; i++){
        src[i] = tmp[len-i-1];
    }
}

/** @brief A function that uses reverse(src, len) to reverse input
 *  lines in the stdin.
 *  @return void
*/
void reverse_input(void){
    char buf[MAXLEN] = "\0";
    size_t len;
    while((len=n_getline(buf, MAXLEN)) != 0){
        if(len > 0){
            reverse(buf, len);
            printf("%s\n", buf);
        }
    }
}

//To signal an EOF in terminal, used CTRL-D
int main(void){
    reverse_input();
    return 0;
}