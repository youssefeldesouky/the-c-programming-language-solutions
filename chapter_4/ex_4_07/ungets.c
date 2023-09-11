/** @file ungets.c
 *  @brief Implementation for Exercise 4-7.
 * 
 *  Write a routine ungets(s) that will push back an entire string
 *  onto the input. Should ungets know about buf and bufp, or should 
 *  it just use ungetch? 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <string.h>

#define BUF_SIZE 100

int getch(void);
void ungetch(int c);
void ungets(char *str);

//To signal an EOF in terminal, used CTRL-D
int main(){
    char *test_str = "Hello, World!";
    ungets(test_str);
    int c;
    while((c = getch()) != EOF){
        putchar(c);
    }
    return 0;
}

/** @brief A function that pushes back an entire string onto the 
 *         characters buffer, emulating the ability to write back
 *         values to stdin.
 *  @param str The string buffer to be pushed onto the buffer.
 *  @return void.
*/
void ungets(char *str){
    size_t len = strlen(str);
    while(len){
        ungetch(str[--len]);
    }
}

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