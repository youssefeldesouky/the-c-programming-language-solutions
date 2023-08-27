/** @file fahrenheit_to_celsius.c
 *  @brief Implementation for Exercise 1-3.
 *  
 *  Exercise 1-3. Modify the temperature conversion program to print
 *  a heading above the table. 
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
    
    fahr = lower;
    puts("****** Fahernheit to Celsius ******");
    puts("-----------------------------------");
    puts("Fahrenheit\t\t    Celsius");
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%10.0f\t\t%11.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}