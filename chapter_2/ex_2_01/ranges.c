/** @file ranges.c
 *  @brief Implementation for Exercise 2-1.
 * 
 *  Write a program to determine the ranges of char, short, int, and long 
 *  variables, both signed and unsigned, by printing appropriate values from
 *  standard headers and by direct computation. Harder if you compute them:
 *  determine the ranges of the various floating-point types.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

//To signal an EOF in terminal, used CTRL-D
int main(void){
    
    signed char sc = 0;
    unsigned char uc = 0;
    signed short ss = 0;
    unsigned short us = 0;
    signed int si = 0;
    unsigned int ui = 0;
    signed long sl = 0;
    unsigned long ul = 0;

    //Signed Minimum
    puts("\nSigned Minimum");
    sc = (signed char)(((unsigned char)~0) ^ ((unsigned char)~0 >> 1));
    printf("%hhd\n", sc);
    ss = (signed short)(((unsigned short)~0) ^ ((unsigned short)~0 >> 1));
    printf("%hd\n", ss);
    si = (signed)((~0U) ^ (~0U >> 1));
    printf("%d\n", si);
    sl = (signed long)((~0UL) ^ (~0UL >> 1));
    printf("%ld\n", sl);

    //Signed Maximum
    puts("\nSigned Maximum");
    sc ^= ~(0);
    printf("%hhd\n", sc);
    ss ^= ~(0);
    printf("%hd\n", ss);
    si ^= ~(0);
    printf("%d\n", si);
    sl ^= ~(0L);
    printf("%ld\n", sl);

    //Unsigned Maximum
    puts("\nUnsigned Maximum");
    uc = ~(0);
    printf("%hhu\n", uc);
    us = ~(0);
    printf("%hu\n", us);
    ui = ~(0U);
    printf("%u\n", ui);
    ul = ~(0UL);
    printf("%lu\n", ul);

    /************ Float ************/
    struct fc{
        unsigned m : 23;  
        unsigned e : 8;
        unsigned s : 1;
    };

    union f{
        float f;
        struct fc comp;
    } flt = { 0.0f };

    //Float Maximum
    puts("\nFloat Maximum");
    flt.comp.m = ~0;
    flt.comp.e = ~1;
    printf("%e\n", flt.f);

    //Float Minimum
    puts("\nFloat Minimum");
    flt.comp.m = 0x0;
    flt.comp.e = 0x1;
    printf("%e\n", flt.f);

    /************ Double ************/
    struct dc{
        unsigned long m : 52; 
        unsigned e : 11;
        unsigned s : 1;
    };

    union d{
        double d;
        struct dc comp;
    } dbl = { 0.0 };

    //Double Maximum
    puts("\nDouble Maximum");
    dbl.comp.m = ~0;
    dbl.comp.e = ~1;
    printf("%le\n", dbl.d);

    //Double Minimum
    puts("\nDouble Minimum");
    dbl.comp.m = 0;
    dbl.comp.e = 1;
    printf("%le\n", dbl.d);

    /************ Long Double ************/
    struct ldc{
        unsigned long m : 64;
        unsigned e : 15;
        unsigned s : 1;
    };

    union ld{
        long double ld;
        struct ldc comp;
    } ldbl = { 0.0L };

    //Long Double Maximum
    puts("\nLong Double Maximum");
    ldbl.comp.m = ~0;
    ldbl.comp.e = ~1;
    printf("%Le\n", ldbl.ld);

    //Long Double Minimum
    puts("\nLong Double Minimum");
    ldbl.comp.m = ~0ULL ^ (~0ULL >> 1);
    ldbl.comp.e = 1;
    printf("%Le\n", ldbl.ld);

    return 0;
}