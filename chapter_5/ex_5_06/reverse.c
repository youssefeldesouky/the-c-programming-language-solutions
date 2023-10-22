/** @file reverse.c
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

//Defines the maximum length of a line
#define MAXLEN 1000

/** @brief A function that swaps the content of two character pointers.
 *  @param a A pointer to the first character.
 *  @param b A pointer to the second character.
 *  @return void.
 */
void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

/** @brief A function that reverses a string recursively in-place.
 *         (Note: Be sure that you're passing a mutable string (array of characters),
 *          otherwise, you will get a Segmentation Fault).
 *  @param s The string to be reversed.
 *  @return void.
 */
void reverse(char *s){
    char *rev_s = s;
    for(; *(rev_s + 1); rev_s++);
    while(s < rev_s) swap(s++, rev_s--);
}

// To signal an EOF in terminal, used CTRL-D
int main(){
    char s[100] = "Hello, World!";
    reverse(s);
    puts(s);
    return 0;
}