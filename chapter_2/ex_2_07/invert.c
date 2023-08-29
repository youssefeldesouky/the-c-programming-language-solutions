/** @file invert.c
 *  @brief Implementation for Exercise 2-7.
 * 
 *  Write a function invert(x,p,n) that returns x with
 *  the n bits that begin at position p inverted (i.e., 1 changed
 *  into 0 and vice versa), leaving the others unchanged.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <stdlib.h>

/** @brief A function that inverts a set of bits starting at a position in a number.
 *  @param x The number that contains the bits to be inverted.
 *  @param p The starting bit location.
 *  @param n The count of bits to be inverted.
 *  @return The result of the bit-inverting process.
*/
unsigned int invert(unsigned int x, unsigned int p, unsigned int n){
    return x ^ ((~0u >> (32u - n)) << p);
}

//Enter the arguments in that order: x, p then n.
int main(int argc, char ** argv){
    if(argc > 3){
        unsigned int x = (unsigned)atol(argv[1]);
        unsigned int p = (unsigned)atol(argv[2]);
        unsigned int n = (unsigned)atol(argv[3]);

        printf("%u\n", invert(x, p, n));
    }
    return 0;
}