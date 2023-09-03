/** @file itob.c
 *  @brief Implementation for Exercise 3-5.
 * 
 *  Write the function itob(n,s,b) that converts the integer 
 *  n into a base b character representation in the string s. In particular,
 *  itob(n,s,16) formats s as a hexadecimal integer in s. 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

//Defines the maximum length of a line
#define MAXLEN 1000

/** @brief A function that converts a base 10 number to a base b number.
 *  @param n The 32-bit integer to be converted.
 *  @param s The destination string that will hold the converted integer.
 *  @param b The base of the converted number.
 *  @return void.
*/
void itob(int n, char *s, int b){
    int idx = 0;
    do{
        s[idx++] = n % b + ((n % b < 10) ? '0' : ('A' - 10));
    }while((n /= b) > 0);

    for(int i = 0, j = idx-1; i <= idx/2 && j >= idx/2; i++, j--){
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    s[idx] = '\0';
}

int main(){
    int number = 123;
    char dest[MAXLEN] = "";
    itob(number, dest, 16);
    puts(dest);
    return 0;
}