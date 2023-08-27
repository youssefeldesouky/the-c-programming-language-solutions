/** @file celsius_to_fahrenheit.c
 *  @brief Implementation for Exercise 1-4.
 *  
 *  Exercise 1-4. Write a program to print the corresponding Celsius
 *  to Fahrenheit table
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

int main(){
    float fahr, celsius;
    float lower, upper, step;

    lower = 0; /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */ 
    
    celsius = lower;
    puts("****** Celsius to Fahernheit ******");
    puts("-----------------------------------");
    puts("Celsius\t\t\t Fahrenheit");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%7.0f\t\t\t%11.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}