/** @file squeeze.c
 *  @brief Implementation for Exercise 2-4.
 * 
 *  Write an alternative version of squeeze(s1,s2) that deletes
 *  each character in s1 that matches any character in the string s2. 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <ctype.h>

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

/** @brief A function that removes characters found in a string
 *         from another string.
 *  @param buf1 The string that will be filtered from characters.
 *  @param buf2 The string that contains the characters to be filtered.
 *  @return void
*/
void squeeze(char buf1[], char buf2[]){
    int i = 0, j =0;
    for(int k = 0; buf2[k] != '\0'; k++){
        if(isalpha(buf2[k])){
            for(i = j = 0; buf1[i] != '\0'; i++){
                if(buf1[i] != buf2[k]){
                    buf1[j++] = buf1[i];
                }
            }
            buf1[j] = '\0';
        }
    }
}

//Enter the first string as the first argument, then the second string
int main(int argc, char ** argv){
    char buf[MAXLEN] = "";
    if(argc > 2){
        copy_str(buf, argv[1], MAXLEN);
        squeeze(buf, argv[2]);
        puts(buf);
    }
    return 0;
}