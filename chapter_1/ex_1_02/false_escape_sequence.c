/** @file false_escape_sequence.c
 *  @brief Implementation for Exercise 1-2.
 *  
 *  Exercise 1-2. Experiment to find out what happens when printf's
 *  argument string contains \c, where c is some character not listed above. 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

int main(){
    printf("Hello, World!\c"); //Compiling this program with GCC, will give a warning
                               //about Unknown esquape sequence, but it will compile
                               //Running the executable will escape the \ as if it was
                               //written as \\ then output the letter c, hence the output
                               //of the executable is "Hello, World!c"
    return 0;
}