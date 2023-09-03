/** @file itoa.c
 *  @brief Implementation for Exercise 3-4.
 * 
 *  In a two's complement number representation, our version of itoa 
 *  does not handle the largest negative number, that is, the value of n
 *  equal to -(2wordsize-1). Explain why not. Modify it to print that value
 *  correctly, regardless of the machine on which it runs. 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

//Defines the maximum length of a line
#define MAXLEN 1000

/** @brief A function that converts a signed integer into a string, which takes
 *         care of the int32 limits.
 *  @param n The 32-bit integer to be converted.
 *  @param s The destination string that will hold the converted integer.
 *  @return void.
*/
void itoa(int n, char *s){
    int idx = 0;
    int sign = 1;
    bool int_min = false;

    if(n == INT_MIN){
        n += 1;
        int_min = true;
    }

    if(n < 0){
        n *= -1;
        sign = -1;
    }

    do{
        s[idx++] = n % 10 + 0x30;
        if(int_min) s[0]++, int_min = false;
    }while((n /= 10) > 0);

    if(sign < 0) s[idx++] = '-';

    for(int i = 0, j = idx-1; i <= idx/2 && j >= idx/2; i++, j--){
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    s[idx] = '\0';
}

int main(){
    int number = INT_MIN;
    char dest[MAXLEN] = "";
    itoa(number, dest);
    puts(dest);
    return 0;
}