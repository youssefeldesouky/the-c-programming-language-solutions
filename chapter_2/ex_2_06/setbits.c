/** @file setbits.c
 *  @brief Implementation for Exercise 2-6.
 * 
 *  Write a function setbits(x,p,n,y) that returns x with the n bits
 *  that begin at position p set to the rightmost n bits of y, leaving
 *  the other bits unchanged.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <stdlib.h>

/** @brief A function that left rotates a number by a set number of bits.
 *  @param x The number to be rotated.
 *  @param n The number of rotations.
 *  @return The rotated number.
*/
unsigned int leftrot(unsigned int x, unsigned int n){
    return (x << (n % 32u)) | x >> ((32u - n) % 32u);
}

/** @brief A function that copies the rightmost n bits in number y
 *         into number x's n bits to the left of bit p.
 *  @param x The destination number.
 *  @param p The starting bit location in the destination number.
 *  @param n The number of bits to be copied/modified.
 *  @param y The source number that has the bits to be copied.
 *  @return The result of the bit-copying process.
*/
unsigned int set_bits(unsigned int x, unsigned int p, unsigned int n, unsigned int y){
    unsigned int mask = y & ~(~0u << n);
    return (x | (mask << p)) & (leftrot((~0u << n), p) | mask << p);
}

//Enter the arguments in that order: x, p, n then y.
int main(int argc, char ** argv){
    if(argc > 4){
        unsigned int x = (unsigned)atol(argv[1]);
        unsigned int p = (unsigned)atol(argv[2]);
        unsigned int n = (unsigned)atol(argv[3]);
        unsigned int y = (unsigned)atol(argv[4]);

        printf("%u\n", set_bits(x, p, n, y));
    }
    return 0;
}