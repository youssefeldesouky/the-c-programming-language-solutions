/** @file strindex.c
 *  @brief Implementation for Exercise 5-6.
 *
 *  Rewrite appropriate programs from earlier chapters and exercises with
 *  pointers instead of array indexing. Good possibilities include getline
 *  (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4),
 *  reverse (Chapter 3), and strindex and getop (Chapter 4).
 *
 *  @author Youssef Samir
 *  @bug No Known Bugs.
 */

#include <stdio.h>
#include <string.h>

/** @brief A function that returns the position of the rightmost occurrence of a
 *         string in another string, or a -1 if it is not found.
 *  @param s The source string to be searched.
 *  @param t The string to be searched for in the source string.
 *  @return The index of the string t in string s, otherwise a -1.
 */
int strindex(char *s, char *t){
    char *s_fwd, *s_rev;
    char *t_rev, *t_fwd;
    t_rev = t_fwd = t;
    s_rev = s_fwd = s;
    for (; *s_rev; s_rev++);
    for (; *(t_rev + 1); t_rev++);
    s = s_rev;
    while(--s >= s_fwd){
        t = t_rev;
        putchar(*s);
        while(t >= t_fwd && *t == *s){
            s--;
            t--;
        }
        if(t < t_fwd)
            return 1;
    }
    return -1;
}

// Enter the arguments in that order: s then t.
int main(int argc, char **argv){
    printf("%p\n",s);
    if (argc > 2){
        printf("%d\n", strindex(argv[1], argv[2]));
    }
    return 0;
}