/** @file fahrenheit_to_celsius_reverse.c
 *  @brief Implementation for Exercise 1-5.
 *  
 *  Exercise 1-5. Modify the temperature conversion program to print 
 *  the table in reverse order, that is, from 300 degrees to 0.
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
    
    puts("****** Fahernheit to Celsius ******");
    puts("-----------------------------------");
    puts("Fahrenheit\t\t    Celsius");
    
    for(fahr = upper; fahr >= lower; fahr -= step){
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%10.0f\t\t%11.1f\n", fahr, celsius);
    }
    return 0;
}