/** @file rightrot.c
 *  @brief Implementation for Exercise 2-8.
 * 
 *  Write a function rightrot(x,n) that returns the value
 *  of the integer x rotated to the right by n positions.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <stdlib.h>

/** @brief A function that right rotates a number by a set number of bits.
 *  @param x The number to be rotated.
 *  @param n The number of rotations.
 *  @return The rotated number.
*/
unsigned int rightrot(unsigned int x, unsigned int n){
    return (x >> (n % 32u)) | x << ((32u - n) % 32u);
}

//Enter the arguments in that order: x then n.
int main(int argc, char ** argv){
    if(argc > 2){
        unsigned int x = (unsigned)atol(argv[1]);
        unsigned int n = (unsigned)atol(argv[2]);

        printf("%u\n", rightrot(x, n));
    }
    return 0;
}