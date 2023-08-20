/** @file fahrenheit_to_celsius.c
 *  @brief Implementation for Exercise 1-15.
 *  
 *  Exercise 1-15. Rewrite the temperature conversion program of 
 *  Section 1.2 to use a function for conversion. 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

/** @brief A function that converts temperature from Fahrenheit to Celsius
 *  @param fahrenheit The Temperature in Fahrenheit
 *  @return The Temperature in Celsius.
*/
double fahrenheit_to_celsius(double fahrenheit){
    return 5.0 * (fahrenheit - 32) / 9.0;
}

//To signal an EOF in terminal, used CTRL-D
int main()
{
    printf("%.2f\n", fahrenheit_to_celsius(98.6));
    return 0;
}