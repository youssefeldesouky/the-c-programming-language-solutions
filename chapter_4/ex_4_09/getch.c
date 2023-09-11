/** @file getch.c
 *  @brief Implementation for Exercise 4-9.
 * 
 *  Our getch and ungetch do not handle a pushed-back EOF correctly.
 *  Decide what their properties ought to be if an EOF is pushed back,
 *  then implement your design. 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <string.h>

#define BUF_SIZE 100

//In the book, the buffer created was an array of chars, and since EOF is a
//Signed integer that has a value of -1, hence a char cannot store EOF value,
//So to solve this issue, we ought to use an array of ints as a buffer.
int input_buf[BUF_SIZE] = {0};
size_t buf_ptr = 0;

/** @brief A function that gets a character from the stdin, but it
 *         supports the use of a buffer, which contains pushed-back values.
 *  @return The character, either from stdin or the characters buffer.
*/
int getch(void){
    return (buf_ptr > 0) ? input_buf[--buf_ptr] : getchar();
}

/** @brief A function that pushes back a character onto the characters buffer,
 *         emulating the ability to write back values to stdin.
 *  @param c The character to be pushed onto the buffer.
 *  @return void.
*/
void ungetch(int c){
    if(buf_ptr >= BUF_SIZE){
        fprintf(stderr, "Error! Buffer is full!\n");
        return;
    }
    input_buf[buf_ptr++] = c;
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