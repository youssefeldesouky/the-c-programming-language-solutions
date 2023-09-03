/** @file expand.c
 *  @brief Implementation for Exercise 3-3.
 * 
 *  Write a function expand(s1,s2) that expands shorthand notations 
 *  like a-z in the string s1 into the equivalent complete list abc...xyz
 *  in s2. Allow for letters of either case and digits, and be prepared to
 *  handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or 
 *  trailing - is taken literally. 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <string.h>

//Defines the maximum length of a line
#define MAXLEN 1000

/** @brief A function that expands shorthand notation, similar to what is used in Regex,
 *         but with the ability to reverse range if needed (ex: Z-A is a valid shorthand notation).
 *  @param s1 The source string that contains the shorthand notation.
 *  @param s2 The destination string that will hold the expanded letters.
 *  @return void.
*/
void expand(char *s1, char *s2){
    size_t len = strlen(s1);
    size_t dashes[99] = {0}, idx_dash = 0, idx_dash_last = -2;
    size_t idx_dest = 0;
    //dashes identification pass
    for(size_t i = 1; i < len - 1; i++){
        if(s1[i] == '-'){
            if(i-2 > idx_dash_last){
                dashes[idx_dash++] = i;
                idx_dash_last = i;
            }
        }
    }
    //expansion pass
    idx_dash = 0;
    for(size_t i = 0; i < len; i++){
        if(i+1 == dashes[idx_dash]){
            char j = s1[i];
            signed char dir = (j <= s1[i+2]) ? 1 : -1;
            for(j = s1[i]; (dir>0)?(j<=s1[i+2]):(j>=s1[i+2]); j+=dir){
                s2[idx_dest++] = j;
            }
            i += 2;
            idx_dash++;
        }else{
            s2[idx_dest++] = s1[i];
        }
    }
    s2[idx_dest] = '\0';
}


//Enter the arguments in that order: src.
int main(int argc, char ** argv){
    char dest[MAXLEN] = "";    
    if(argc > 1){
        expand(argv[1], dest);
        puts(dest);
    }
    return 0;
}