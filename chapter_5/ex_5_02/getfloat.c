/** @file getfloat.c
 *  @brief Implementation for Exercise 5-2.
 *
 *  Write getfloat, the floating-point analog of getint. 
 *  What type does getfloat return as its function value?
 *
 *  @author Youssef Samir
 *  @bug No Known Bugs.
 */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);

/** @brief A function that parses a double precision floating point number from a string.
 *  @param pn Pointer to the destination double variable.
 *  @return -1 if EOF, 0 if NaN and any other value if a number is parsed.
 */
int getfloat(double *pn){
    int c, sign = 1;
    double power = 1;
    
    while(isspace(c = getch()));

    if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
        ungetch(c);
        return 0;
    }

    if(c == '+' || c == '-' || c == '.'){
        int temp = getch();
        if(!isdigit(temp)){
            ungetch(temp);
            return 0;
        }else{
            if(c != '.') sign = (c == '-') ? -1 : 1;
            ungetch(temp);
        }
    }

    for(*pn = 0; isdigit(c); c = getch()){
        *pn = *pn * 10 + (c - '0');
    }

    if(c == '.'){
        c = getch();
        for (; isdigit(c); c = getch()){
            *pn = *pn * 10 + (c - '0');
            power *= 10;
        }
    }

    *pn = (*pn / power) * sign;
    if(c != EOF){
        ungetch(c);
    }
    return c;
}

// To signal an EOF in terminal, used CTRL-D
int main(){
    double value = 0.0;
    double sum = 0.0;

    do {
        printf("Enter a number to add to the total sum: ");
        sum += value;
    } while(getfloat(&value) != EOF);

    putchar('\n');
    printf("The total sum is %lf\n", sum);
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