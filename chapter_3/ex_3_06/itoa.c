/** @file itoa.c
 *  @brief Implementation for Exercise 3-6.
 * 
 *  Write a version of itoa that accepts three arguments
 *  instead of two. The third argument is a minimum field width;
 *  the converted number must be padded with blanks on the left
 *  if necessary to make it wide enough. 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

//Defines the maximum length of a line
#define MAXLEN 1000

/** @brief A function that converts a signed integer into a string with the ability
 *         to specifiy the minimum field width of the number, making the number right-aligned.
 *  @param n The 32-bit integer to be converted.
 *  @param s The destination string that will hold the converted integer.
 *  @param width The minimum width of the field, if the resulting number has less
 *               digits than the width, then the final string is padded with spaces
 *               to the left to satisfy the width requirements.
 *  @return void.
*/
void itoa(int n, char *s, int width){
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
        width--;
    }while((n /= 10) > 0);
    if(sign < 0) s[idx++] = '-', width--;
    for(int i = 0; width > 0 && i < width; s[idx++] = ' ', i++);
    for(int i = 0, j = idx-1; i <= idx/2 && j >= idx/2; i++, j--){
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    s[idx] = '\0';
}

int main(){
    int number = 133354;
    char dest[MAXLEN] = "";
    itoa(number, dest, 5);
    puts(dest);
    return 0;
}