/** @file bitcount.c
 *  @brief Implementation for Exercise 2-9.
 * 
 *  In a two's complement number system, x &= (x-1) deletes
 *  the rightmost 1-bit in x. Explain why. Use this observation
 *  to write a faster version of bitcount.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <stdlib.h>

/** @brief A function that counts the number of set bits in a number.
 *  @param x The number to be counted.
 *  @return The count of set bits in the number.
*/
unsigned int bitcount(unsigned int x){
    unsigned int count = 0;
    while(x) {
        count++;
        x &= x-1;
    }
    return count;
}

//Enter the arguments in that order: x.
int main(int argc, char ** argv){
    if(argc > 1){
        unsigned int x = (unsigned)atol(argv[1]);

        printf("%u\n", bitcount(x));
    }
    return 0;
}