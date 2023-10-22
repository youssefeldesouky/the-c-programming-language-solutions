/** @file strncat.c
 *  @brief Implementation for Exercise 5-5.
 *
 *  Write versions of the library functions strncpy, strncat, and strncmp,
 *  which operate on at most the first n characters of their argument strings.
 *  For example, strncpy(s,t,n) copies at most n characters of t to s.
 *  Full descriptions are in Appendix B.
 *
 *  @author Youssef Samir
 *  @bug No Known Bugs.
 */

#include <stdio.h>

#define MAXLEN 100

//Had to change the function name, because it causes conflict with the one defined in the libc.
/** @brief A function that copies up to n characters from string t to string s.
 *  @param s The destination string.
 *  @param t The source string.
 *  @param n The number of characters to be copied, including the Null Terminator.
 *  @return A pointer to the source string.
 */
char *my_strncat(char *s, char *t, size_t n){
    char *ptr;
    for (ptr = s; *ptr; ptr++);
    while (n-- && (*ptr++ = *t++));
    return s;
}

// To signal an EOF in terminal, used CTRL-D
int main(){
    char s[MAXLEN] = "Hello, ";
    char t[] = "World!";
    puts(my_strncat(s, t, 7));
    return 0;
}
