/** @file polish.c
 *  @brief Implementation for Exercise 4-10.
 * 
 *  An alternate organization uses getline to read an entire input
 *  line; this makes getch and ungetch unnecessary. Revise the calculator
 *  to use this approach. 
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
#define NUMBER 1
#define CMD 2
#define SET_VAR 3
#define GET_VAR 4
#define GET_LAST 5
#define BUF_SIZE 1000
#define VAR_SIZE 26

int n_getline(char buf[], size_t len);
int getop(char s[]);
double atof(const char *src);
void push(double value);
double pop(void);
double peek(void);

//Commands Prototypes
void top(void);
void duplicate(void);
void swap(void);
void clear(void);
void sine(void);
void exponent(void);
void power(void);

char input_buf[BUF_SIZE] = {0};
size_t buf_ptr = 0;

//Used in conjunction with newline, to prevent popping the top of the stack.
bool top_called = false;

//Compile with the option -lm coming after the source file name to include the math library
//To stop error messages from displaying, redirect it to /dev/null, ex: ./a.out 2> /dev/null
//To signal an EOF in terminal, used CTRL-D
int main(){
    char buf[BUF_SIZE] = "";
    int type = 0;
    double op2 = 0.0;
    bool error = false;
    double variables[VAR_SIZE] = { 0.0 };
    double last_value = 0.0;
    while(n_getline(input_buf, BUF_SIZE)){
        buf_ptr = 0;
        while((type = getop(buf)) != '\0'){
            switch (type)
            {
                case NUMBER:
                    push(atof(buf));
                    break;
                case CMD:
                    if(!strcmp(buf, "clr") || !strcmp(buf, "c")){
                        clear();
                    }else if(!strcmp(buf, "top")){
                        top();
                    }else if(!strcmp(buf, "dup")){
                        duplicate();
                    }else if(!strcmp(buf, "swp")){
                        swap();
                    }else if(!strcmp(buf, "sin")){
                        sine();
                    }else if(!strcmp(buf, "exp")){
                        exponent();
                    }else if(!strcmp(buf, "pow")){
                        power();
                    }else{
                        fprintf(stderr, "Error! Incorrect Operator!\n");
                        error = true;
                        break;
                    }
                    break;
                case SET_VAR:
                    variables[tolower(buf[0]) - 'a'] = pop();
                    break;
                case GET_VAR:
                    push(variables[tolower(buf[0]) - 'a']);
                    break;
                case GET_LAST:
                    push(last_value);
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
                        if(top_called){
                            printf("Ans:\t%.8g\n", (last_value = peek()));
                            top_called = false;
                        }else{
                            printf("Ans:\t%.8g\n", (last_value = pop()));
                        }
                    }else{
                        error = false;
                    }
                    break;
                default:
                    error = true;
                    break;
            }
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

/** @brief A function that returns the top of a stack without popping.
 *  @return The top value, or a 0.0 if the stack was empty.
*/
double peek(void){
    if(stack_ptr == 0){
        fprintf(stderr, "Error! Stack is empty!\n");
        return 0.0;
    }
    return stack[stack_ptr - 1];
}

/** @brief A function that gets a character from the stdin, but it
 *         supports the use of a buffer, which contains pushed-back values.
 *  @return The character, either from stdin or the characters buffer.
*/
int getch(void){
    return input_buf[buf_ptr++];
}

/** @brief A function that pushes back a character onto the characters buffer,
 *         emulating the ability to write back values to stdin.
 *  @param c The character to be pushed onto the buffer.
 *  @return void.
*/
void ungetch(void){
    if(buf_ptr <= 0){
        fprintf(stderr, "Error! Buffer is full!\n");
        return;
    }
    buf_ptr--;
}

/** @brief A function that moves a line from stdin to a buffer while keeping track
 *         of its length. (This is modified to include the Newline character for it
 *         to work with the calculator). 
 *  @param buf The string buffer that will contain the captured line
 *  @param len The maximum length of a line
 *  @return The length of the captured line
*/
int n_getline(char buf[], size_t len){
    int c = '\0';
    size_t i = 0;
    for(i = 0; i <= len && (c = getchar()) != EOF; i++){
        buf[i] = c;
        if(c == '\n'){
            break;
        }
    }
    buf[++i] = '\0';
    if(c == EOF) return 0;
    return i;
}

/** @brief A function that reads characters entered by the user
 *         and determines its type.
 *  @param s A character array that will store the number read from stdin.
 *  @return Returns either a code that represents the operator or an indicator
 *          that a special type has been captured (Number, Variable, Special Operator).
*/
int getop(char s[]){
    int c;
    size_t str_ptr = 0;
    while(isblank((c = getch())));
    ungetch();
    while((c = getch()) != EOF && c != '\0'){
        if(!isalnum(c) && c != '.'){
            if(str_ptr > 0){
                ungetch();
                s[str_ptr] = '\0';
                if(isdigit(s[str_ptr - 1])){
                    return NUMBER;
                }else if(strlen(s) == 1){
                    return GET_VAR;
                }else{
                    return CMD;
                }
            }else{
                int temp = 0;
                if((c == '+' || c == '-') && isdigit((temp = getch()))){
                    s[str_ptr++] = c;
                    ungetch();
                }else if((c == '=')){
                    if(isalpha(temp = getch())){
                        s[str_ptr++] = temp;
                        s[stack_ptr] = '\0';
                        return SET_VAR;
                    }else{
                        ungetch();
                    }
                }else if((c == '_')){
                    return GET_LAST;
                }else{
                    if(temp) ungetch();
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

/** @brief A function that print the top of a stack without popping it.
 *  @return void.
*/
void top(void){
    top_called = true;
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

/** @brief A function that calculates the sine of a value.
 *  @return void.
*/
void sine(void){
    if(stack_ptr < 1){
        fprintf(stderr, "Error! Insufficient elements on the stack!\n");
    }
    push(sin(pop()));
}

/** @brief A function that calculates the value of e ^ (top of the stack).
 *  @return void.
*/
void exponent(void){
    if(stack_ptr < 1){
        fprintf(stderr, "Error! Insufficient elements on the stack!\n");
    }
    push(exp(pop()));
}

/** @brief A function that calculates the value x ^ y, y and x are the
 *         topmost values on the stack respectively.
 *  @return void.
*/
void power(void){
    if(stack_ptr < 2){
        fprintf(stderr, "Error! Insufficient elements on the stack!\n");
    }
    double op1 = pop();
    double op2 = pop();
    push(pow(op2, op1));
}