/** @file any.c
 *  @brief Implementation for Exercise 2-5.
 * 
 *  Write the function any(s1,s2), which returns the first location in a string s1
 *  where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
 *  (The standard library function strpbrk does the same job but returns a pointer to the 
 *  location.) 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <ctype.h>

/** @brief A function that if any character in the second string
 *         occurs in the first, it returns its index, otherwise return -1.
 *  @param buf1 The string that will be searched.
 *  @param buf2 The string that contains the characters to be searched for.
 *  @return The index of the character found
*/
int any(char buf1[], char buf2[]){
    for(int i = 0; buf2[i] != '\0'; i++){
        if(isalnum(buf2[i])){
            for(int j = 0; buf1[j] != '\0'; j++){
                if(buf1[j] == buf2[i]) return j;
            }
        }
    }
    return -1;
}

//Enter the first string as the first argument, then the second string
int main(int argc, char ** argv){
    if(argc > 2){
        printf("%d\n", any(argv[1], argv[2]));
    }
    return 0;
}