/** @file strend.c
 *  @brief Implementation for Exercise 5-4.
 *
 *  Write the function strend(s,t), which returns 1 if the string
 *  t occurs at the end of the string s, and zero otherwise.
 *
 *  @author Youssef Samir
 *  @bug No Known Bugs.
 */

#include <stdio.h>

/** @brief A function that checks if string t is at the end of string s.
 *  @param s The destination string.
 *  @param t The string that will be checked for occurence in string s.
 *  @return Returns a 1 if t occurs at the end of s, otherwise, a 0.
 */
int strend(char *s, char *t){
    char *ptr;
    for(ptr = t; *(ptr+1); ptr++);
    for (; *(s+1); s++);
    while(t <= ptr && *s-- == *ptr--);
    return *(ptr + 1) == *(s + 1);
}

// To signal an EOF in terminal, used CTRL-D
int main(){
    char s[] = "Hello";
    char t[] = "ello";
    printf("%d\n", strend(s, t));
    return 0;
}
