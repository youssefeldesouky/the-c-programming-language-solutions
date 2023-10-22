/** @file atoi.c
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
#include <ctype.h>
#include <limits.h>

//Defines the maximum length of a line
#define MAXLEN 1000

/** @brief A function parses an integer from a string.
 *  @param s The source string that will be searched for an integer value.
 *  @return The parsed integer if it exists, otherwise a 0.
 */
int atoi(char *s){
    int res = 0;
    int sign = 1;
    for(;isspace(*s); s++);
    if(*s == '-' || *s == '+'){
        sign = (*s == '-') ? -1 : 1;
        s++;
    }
    while(isdigit(*s)){
        res = res * 10 + (*s - '0');
        s++;
    }
    return res * sign;
}

// To signal an EOF in terminal, used CTRL-D
int main(){
    char buf[MAXLEN] = "    2356";
    printf("%d\n", atoi(buf));
    return 0;
}