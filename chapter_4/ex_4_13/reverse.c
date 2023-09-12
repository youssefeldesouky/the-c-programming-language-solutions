/** @file reverse.c
 *  @brief Implementation for Exercise 4-13.
 * 
 *  Write a recursive version of the function reverse(s), 
 *  which reverses the string s in place. 
 *  Note: This is not the best way to implement this function.
 *  
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

/** @brief A function that swaps the contents of two character pointers.
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
    static int size = 0;
    static int j = 0;
    if(*s){
        size++;
        reverse(s+1);
        if(j >= (size / 2)) return;
        swap((s - ((size - 1) - j) + j), s);
        j++;
    }
}

//To signal an EOF in terminal, used CTRL-D
int main(){
    char s[100] = "Hello, World!";
    reverse(s);
    puts(s);
    return 0;
}