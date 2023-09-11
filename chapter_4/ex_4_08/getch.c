/** @file getch.c
 *  @brief Implementation for Exercise 4-8.
 * 
 *  Suppose that there will never be more than one character
 *  of pushback. Modify getch and ungetch accordingly.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <string.h>

int buf = EOF;

/** @brief A function that gets a character from the stdin, but it
 *         supports the use of a buffer, which contains a pushed-back value.
 *  @return The character, either from stdin or the character buffer.
*/
int getch(void){
    if(buf == EOF){
        return getchar();
    }
    int c = buf;
    buf = EOF;
    return c;
}

/** @brief A function that pushes back a character onto the character buffer,
 *         emulating the ability to write back values to stdin.
 *  @param c The character to be pushed onto the buffer.
 *  @return void.
*/
void ungetch(int c){
    //Using the assumption that there will never be more than 
    //one pushed-back character, We don't need to check if the
    //Buffer is already occupied or not before the assignment.
    buf = c;
}

//To signal an EOF in terminal, used CTRL-D
int main(){
    printf("Enter a character to be pushed to the buffer: ");
    int c;
    c = getch();
    ungetch(c);
    printf("The pushed back character is %c\n", getch());
    return 0;
}