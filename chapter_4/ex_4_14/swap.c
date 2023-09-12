/** @file swap.c
 *  @brief Implementation for Exercise 4-14.
 * 
 *  Define a macro swap(t,x,y) that interchanges two arguments of type t.
 *  (Block structure will help.)
 *  
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

/** @brief A macro that swaps the contents of two generic pointers.
 *  @param t The type of both pointers.
 *  @param x A pointer to the first variable.
 *  @param y A pointer to the second variable.
 *  @return void.
*/
#define SWAP(t,x,y){\
    t temp = *x;\
    *x = *y;\
    *y = temp;\
}

//To signal an EOF in terminal, used CTRL-D
int main(){
    double x = 3;
    double y = 2;
    printf("Before\t-->\tx: %lf\ty: %lf\n", x, y);
    SWAP(int, &x, &y);
    printf("After\t-->\tx: %lf\ty: %lf\n", x, y);
    return 0;
}