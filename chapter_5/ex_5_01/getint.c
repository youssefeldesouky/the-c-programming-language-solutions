/** @file getint.c
 *  @brief Implementation for Exercise 5-1.
 *
 *  As written, getint treats a + or - not followed by a digit as 
 *  a valid representation of zero. Fix it to push such a character
 *  back on the input.
 *
 *  @author Youssef Samir
 *  @bug No Known Bugs.
 */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);

/** @brief A function that parses a signed number integer from a string.
 *  @param pn Pointer to the destination integer variable.
 *  @return -1 if EOF, 0 if NaN and any other value if a number is parsed.
 */
int getint(int *pn){
    int c, sign = 1;
    
    while(isspace(c = getch()));

    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }

    if(c == '+' || c == '-'){
        int temp = getch();
        if(!isdigit(temp)){
            ungetch(temp);
            return 0;
        }else{
            sign = (c == '-') ? -1 : 1;
            ungetch(temp);
        }
    }

    for(*pn = 0; isdigit(c); c = getch()){
        *pn = *pn * 10 + (c - '0');
    }
    *pn *= sign;
    if(c != EOF){
        ungetch(c);
    }
    return c;
}

// To signal an EOF in terminal, used CTRL-D
int main(){
    int value = 0;
    int sum = 0;

    do {
        printf("Enter a number to add to the total sum: ");
        sum += value;
    } while(getint(&value) != EOF);

    putchar('\n');
    printf("The total sum is %d\n", sum);
    return 0;
}

int buf = EOF;

/** @brief A function that gets a character from the stdin, but it
 *         supports the use of a buffer, which contains a pushed-back value.
 *  @return The character, either from stdin or the character buffer.
 */
int getch(void)
{
    if (buf == EOF)
    {
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
void ungetch(int c)
{
    // Using the assumption that there will never be more than
    // one pushed-back character, We don't need to check if the
    // Buffer is already occupied or not before the assignment.
    buf = c;
}