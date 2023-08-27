/** @file decomment.c
 *  @brief Implementation for Exercise 1-23.
 * 
 *  Write a program to remove all comments from a C program.
 *  Don't forget to handle quoted strings and character constants
 *  properly. C comments don't nest.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <stdbool.h>

//Defines the state of the cursor, whether it is inside a string or not
enum STR_STATE {OUT_STR, IN_STR};

//Defines the state of the cursor, whether it is inside a comment or not
enum CMNT_STATE {OUT_CMNT, IN_CMNT};

/** @brief A function that reads a C source code provided in the stdin file
 *         then filters it out from C and C++ comments and prints out the result
 *         in the stdout.
 *  @param remove_cpp_comments Whether to affect C++ comments or not (single-line comments).
 *  @return void
*/
void decomment(bool remove_cpp_comments){
    int c = 0, prev_c = 0;
    enum STR_STATE str_state = OUT_STR; 
    enum CMNT_STATE cmnt_state = OUT_CMNT;
    bool in_cpp_cmnt = false;

    while(c != EOF){
        prev_c = c;
        c = getchar();

        if(c == '\"' && prev_c != '\\' && cmnt_state == OUT_CMNT) str_state = !str_state;

        if(str_state == OUT_STR){
            if(c == '/'){
                if(cmnt_state == OUT_CMNT){
                    prev_c = c;
                    c = getchar();
                    if(c == '*'){
                    cmnt_state = IN_CMNT;
                    }else if(remove_cpp_comments && c == '/'){
                        in_cpp_cmnt = true;
                        cmnt_state = IN_CMNT;
                    }else{
                        putchar(prev_c);
                    }
                }else if(cmnt_state == IN_CMNT){
                    if(prev_c == '*'){
                        cmnt_state = OUT_CMNT;
                        continue;
                    }
                }
            }else if(in_cpp_cmnt && cmnt_state == IN_CMNT && c == '\n'){
                cmnt_state = OUT_CMNT;
                in_cpp_cmnt = false;
            }
        }

        if(cmnt_state == OUT_CMNT && c != EOF) putchar(c);
    }
}

//To signal an EOF in terminal, used CTRL-D
//To feed the file into the program, use redirection, i.e. "./a.out < file.c"
int main(void){
    decomment(false);
    return 0;
}