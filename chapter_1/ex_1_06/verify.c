/** @file verify.c
 *  @brief Implementation for Exercise 1-6.
 *  
 *  Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

//To signal an EOF in terminal, used CTRL-D
int main(){
    printf("%d\n", getchar() != EOF);
    return 0;
}