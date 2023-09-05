/** @file polish.c
 *  @brief Implementation for Exercise 4-4.
 * 
 *  Add the commands to print the top elements of the stack without popping,
 *  to duplicate it, and to swap the top two elements. Add a command to clear the stack.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define STACK_SIZE 100
#define NUMBER 0
#define CMD 1
#define BUF_SIZE 100

int getop(char s[]);
double atof(const char *src);
void push(double value);
double pop(void);

//Commands Prototypes
void top(void);
void duplicate(void);
void swap(void);
void clear(void);

//Compile with the option -lm coming after the source file name to include the math library
//To stop error messages from displaying, redirect it to /dev/null, ex: ./a.out 2> /dev/null
//To signal an EOF in terminal, used CTRL-D
int main(){
    char buf[BUF_SIZE] = "";
    int type = 0;
    double op2 = 0.0;
    bool error = false;
    while((type = getop(buf)) != EOF){
        switch (type)
        {
            case NUMBER:
                push(atof(buf));
                break;
            case CMD:
                if(!strcmp(buf, "clr") || !strcmp(buf, "c")){
                    clear();
                }else if(!strcmp(buf, "top") || !strcmp(buf, "t")){
                    top();
                }else if(!strcmp(buf, "dup") || !strcmp(buf, "d")){
                    duplicate();
                }else if(!strcmp(buf, "swp") || !strcmp(buf, "s")){
                    swap();
                }
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if(op2 == 0.0){
                    fprintf(stderr, "Error! Cannot divide by zero!\n");
                    error = true;
                    break;
                }
                push(pop() / op2);
                break;
            case '%':
                op2 = pop();
                if(op2 == 0.0){
                    fprintf(stderr, "Error! Cannot divide by zero!\n");
                    error = true;
                    break;
                }
                push(fmod(pop(), op2));
                break;
            case '\n':
                if(!error){
                    printf("Ans:\t%.8g\n", pop());
                }else{
                    error = false;
                }
                break;
            default:
                error = true;
                break;
        }
    } 
    return 0;
}

/** @brief A function that parses a double-precision floating point number
 *         from a string, which can also handle scientific notation.
 *  @param src The source string that will be parsed.
 *  @return The parsed double-precision floating point number.
*/
double atof(const char *src){
    bool expo = false, pwr = false;
    int sign = 1, expo_sign = 1;
    size_t i = 0;
    size_t exponent = 0;
    double power = 1.0;
    double value = 0.0;
    //escape whitespace
    for(i = 0; isspace(src[i]); i++);
    //get sign
    if(src[i] == '-' || src[i] == '+'){
        sign = (src[i++] == '-') ? -1 : 1;
    }
    for(; src[i]; i++){
        //begin counting power
        if(src[i] == '.'){
            pwr = true;
        }
        //enable exponential
        else if(i < strlen(src) - 1 && (src[i] == 'e' || src[i] == 'E')){
            expo = true;
            if(i < strlen(src) - 2 && (src[i+1] == '+' || src[i+1] == '-')){
                expo_sign = (src[++i] == '-') ? -1 : 1;
            }
        }
        else if(isdigit(src[i])){
            if(!expo){
                if(pwr){
                    power *= 10;
                }
                value = value * 10 + (src[i] - '0');
            }else{
                exponent = exponent * 10 + (src[i] - '0');
            }
        }
        else{
            break;
        }
    }
    if(expo){
        for(size_t j = 0; j < exponent; j++){
            (expo_sign < 0) ? (value /= 10) : (value *= 10);
        }
    }
    return sign * value / power;
}


double stack[STACK_SIZE] = { 0.0 };
size_t stack_ptr = 0;

/** @brief A function that pushes a value to a stack of doubles.
 *  @param value The value to be pushed.
 *  @return void.
*/
void push(double value){
    if(stack_ptr >= STACK_SIZE){
        fprintf(stderr, "Error! Stack is full!\n");
        return;
    }
    stack[stack_ptr++] = value;
}

/** @brief A function that pops the top of a stack.
 *  @return The popped value, or a 0.0 if the stack was empty.
*/
double pop(void){
    if(stack_ptr == 0){
        fprintf(stderr, "Error! Stack is empty!\n");
        return 0.0;
    }
    return stack[--stack_ptr];
}

int input_buf[BUF_SIZE] = {0};
size_t buf_ptr = 0;

/** @brief A function that gets a character from the stdin, but it
 *         supports the use of a buffer, which contains pushed-back values.
 *  @return The character, either from stdin or the characters buffer.
*/
int getch(){
    return (buf_ptr > 0) ? input_buf[--buf_ptr] : getchar();
}

/** @brief A function that pushes back a character onto the characters buffer,
 *         emulating the ability to write back values to stdin.
 *  @param c The character to be pushed onto the buffer.
*/
void ungetch(int c){
    if(buf_ptr >= BUF_SIZE){
        fprintf(stderr, "Error! Buffer is full!\n");
        return;
    }
    input_buf[buf_ptr++] = c;
}

/** @brief A function that reads characters entered by the user
 *         and determines whether it is an operator or a number.
 *  @param s A character array that will store the number read from stdin.
 *  @return Returns either a code that represents the operator or an indicator
 *          that a number has been read.
*/
int getop(char s[]){
    int c;
    size_t str_ptr = 0;
    while(isblank((c = getch())));
    ungetch(c);
    while((c = getch()) != EOF && c != '\0'){
        if(!isalnum(c) && c != '.'){
            if(str_ptr > 0){
                ungetch(c);
                s[str_ptr] = '\0';
                if(isdigit(s[str_ptr - 1])){
                    return NUMBER;
                }else{
                    return CMD;
                }
                
            }else{
                int temp = 0;
                if( (c == '+' || c == '-') && isdigit((temp = getch()))){
                    s[str_ptr++] = c;
                    ungetch(temp);
                }else{
                    if(temp) ungetch(temp);
                    return c;
                }
            }
        }else{
            s[str_ptr++] = c;
        }
    }
    return c;
}

/** @brief A function that clears the stack.
 *  @return void.
*/
void clear(void){
    stack_ptr = 0;
}

/** @brief A function that print the top of a stack without popping it,
 *         by incrementing the stack pointer to compensate for the decrement
 *         done when Enter is pressed.
 *  @return void.
*/
void top(void){
    stack_ptr += stack_ptr < STACK_SIZE;
}

/** @brief A function that duplicates the current top value on the stack.
 *  @return void.
*/
void duplicate(void){
    double top = pop();
    push(top);
    push(top);
}

/** @brief A function that swaps the top two values on the stack.
 *  @return void.
*/
void swap(void){
    if(stack_ptr < 2){
        fprintf(stderr, "Error! Insufficient elements on the stack!\n");
    }
    double op1 = pop();
    double op2 = pop();
    push(op1);
    push(op2);
}