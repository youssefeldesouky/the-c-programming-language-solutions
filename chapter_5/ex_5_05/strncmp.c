/** @file strncmp.c
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
/** @brief A function that compares string s to string t up to n letters.
 *  @param s The destination string.
 *  @param t The source string.
 *  @param n The number of characters to be compared.
 *  @return A 0 if both strings match (either fully or at n letters), a positive number if s is greater
 *          than t and a negative number if t is greater than s.
 */
int my_strncmp(char *s, char *t, size_t n){
    for (; n && *t && *s && *s == *t; s++, t++, n--);
    return (n == 0) ? *(s-1) - *(t-1) : *(s) - *(t);
}

// To signal an EOF in terminal, used CTRL-D
int main(){
    char s[MAXLEN] = "Hello, World!";
    char t[] = "Hello, World!";
    printf("%d\n", my_strncmp(s, t, sizeof(t)));
    return 0;
}
