/** @file getline.c
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

#define MAXLEN 100

/** @brief A function that moves a line from stdin to a buffer while keeping track
 *         of its length
 *  @param buf The string buffer that will contain the captured line
 *  @param len The maximum length of a line
 *  @return The length of the captured line.
 */
int n_getline(char *buf, size_t len){
    int c = '\0';
    size_t i = 0;
    for (i = 0; i <= len && (c = getchar()) != EOF; i++){
        if (c == '\n'){
            break;
        }
        *buf++ = c;
    }
    *buf = '\0';
    if (c == EOF) return 0;
    return (int)i;
}

// To signal an EOF in terminal, used CTRL-D
int main(){
    char buf[MAXLEN] = "";
    n_getline(buf, MAXLEN);
    puts(buf);
    return 0;
}
