/** @file atof.c
 *  @brief Implementation for Exercise 4-2.
 * 
 *  Extend atof to handle scientific notation of the
 *  form 123.45e-6 where a floating-point number may be
 *  followed by e or E and an optionally signed exponent.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

/** @brief A function that parses a double-precision floating point number
 *         from a string, which can also handle scientific notation.
 *  @param src The source string that will be parsed.
 *  @return The parsed double-precision floating point number.
*/
double atof(const char *src){
    bool expo = false, pwr = false;
    int sign = 1, expo_sign = 1;
    size_t i = 0;
    size_t exponent = 0;
    double power = 1.0;
    double value = 0.0;
    //escape whitespace
    for(i = 0; isspace(src[i]); i++);
    //get sign
    if(src[i] == '-' || src[i] == '+'){
        sign = (src[i++] == '-') ? -1 : 1;
    }
    for(; src[i]; i++){
        //begin counting power
        if(src[i] == '.'){
            pwr = true;
        }
        //enable exponential
        else if(i < strlen(src) - 1 && (src[i] == 'e' || src[i] == 'E')){
            expo = true;
            if(i < strlen(src) - 2 && (src[i+1] == '+' || src[i+1] == '-')){
                expo_sign = (src[++i] == '-') ? -1 : 1;
            }
        }
        else if(isdigit(src[i])){
            if(!expo){
                if(pwr){
                    power *= 10;
                }
                value = value * 10 + (src[i] - '0');
            }else{
                exponent = exponent * 10 + (src[i] - '0');
            }
        }
        else{
            break;
        }
    }
    if(expo){
        for(size_t j = 0; j < exponent; j++){
            (expo_sign < 0) ? (value /= 10) : (value *= 10);
        }
    }
    return sign * value / power;
}

// To signal an EOF in terminal, used CTRL-D
int main(){
    char src[] = "3.14159265358979";
    printf("%.14lf\n", atof(src));
    return 0;
}