/** @file itoa.c
 *  @brief Implementation for Exercise 4-12.
 * 
 *  Adapt the ideas of printd to write a recursive version of itoa; that is,
 *  convert an integer into a string by calling a recursive routine. 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <limits.h>

//Defines the maximum length of a line
#define MAXLEN 1000

/** @brief A function that converts a signed integer into a string recursively, which takes
 *         care of the int32 limits.
 *  @param n The 32-bit integer to be converted.
 *  @param s The destination string that will hold the converted integer.
 *  @return void.
*/
void itoa(int n, char *s){
    static size_t i = 0;
    char c;
    //This variable is used when the integer is equal to the minimum int32 value
    //Without it, the value will be erroneous when its sign is flipped
    //All it does, is to increment the integer value when the above condition is true
    //Then add a 1 to the final digit place in the string.
    int compensator = 0;
    if(n < 0){
        s[i++] = '-';
        if(n == INT_MIN){
            n += 1;
            compensator = 1;
        }
        n = -n;
    }
    if(n / 10){
        itoa(n / 10, s);
    }
    c = '0' + n % 10 + compensator;
    s[i++] = c;
    s[i] = '\0';
}

//To signal an EOF in terminal, used CTRL-D
int main(){
    char buf[MAXLEN] = "";
    itoa(INT_MIN, buf);
    puts(buf);
    return 0;
}