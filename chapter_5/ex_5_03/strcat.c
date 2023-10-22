/** @file strcat.c
 *  @brief Implementation for Exercise 5-3.
 *
 *  Write a pointer version of the function strcat that we showed
 *  in Chapter 2: strcat(s,t) copies the string t to the end of s.
 *
 *  @author Youssef Samir
 *  @bug No Known Bugs.
 */

#include <stdio.h>

#define MAXLEN 100

/** @brief A function that concatenates a string t to a string s.
 *         (Make sure string s can accomodate the addition of string t).
 *  @param s The destination string.
 *  @param t The string that will be concatenated to string s.
 *  @return Pointer to string s.
 */
char *strcat(char *s, const char *t){
    char *ptr;
    for(ptr = s; *ptr; ptr++);
    while((*ptr++ = *t++));
    return s;
}

// To signal an EOF in terminal, used CTRL-D
int main(){
    char s[MAXLEN] = "Hello, ";
    char t[] = "World!";
    puts(strcat(s, t));
    return 0;
}
