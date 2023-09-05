/** @file strindex.c
 *  @brief Implementation for Exercise 4-1.
 * 
 *  Write the function strindex(s,t) which returns the position
 *  of the rightmost occurrence of t in s, or -1 if there is none. 
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
int strindex(const char *s, const char *t){
    for(int i = (int)strlen(s) - 1; i >= 0; i--){
        int j = (int)strlen(t) - 1;
        int k = i - j;
        for(; j >= 0 && s[i] == t[j]; i--, j--);
        if(j < 0) return k;
    }
    return -1;
}

//Enter the arguments in that order: s then t.
int main(int argc, char ** argv){
    if(argc > 2){
        printf("%d\n", strindex(argv[1], argv[2]));
    }
    return 0;
}