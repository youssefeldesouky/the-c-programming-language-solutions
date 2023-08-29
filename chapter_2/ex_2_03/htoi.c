/** @file htoi.c
 *  @brief Implementation for Exercise 2-3.
 * 
 *  Write a function htoi(s), which converts a string of hexadecimal digits
 *  (including an optional 0x or 0X) into its equivalent integer value.
 *  The allowable digits are 0 through 9, a through f, and A through F. 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <ctype.h>

/** @brief A function that converts a hexadecimal character and 
 *         converts it to its equivalent integer value.
 *  @param x The character that holds the hexadecimal digit
 *  @return The integer value of the hexadecimal digit
*/
int hex_to_int(char x){
    x = toupper(x);
    if(isdigit(x)) return (x - '0');
    if(x >= 'A' && x <= 'F') return (x - 'A' + 10);
    else return -1;
}

/** @brief A function that converts a string that contains a hexadecimal value
 *         into its equivalent integer value. 
 *  @param s The string buffer that contains the hexadecimal value
 *  @return The integer value of the hexadecimal value
*/
unsigned long int htoi(char s[]){
    int i = 0;
    unsigned long int final = 0;
    while(s[i] != '\0'){
        if(i > 0 && tolower(s[i]) == 'x' && s[i-1] == '0'){
            i++;
            while(s[i] != '\0' && s[i] != ' ' && s[i] != '\n' && s[i] != '\t'){
                if(hex_to_int(s[i]) == -1) break;
                final = final * 16 + hex_to_int(s[i]);
                i++;
            }
            if(final != 0) return final;
        }
        i++;
    }
    return 0;
}

//Enter the hexadecimal string as an argument
int main(int argc, char ** argv){
    if(argc > 1){
        printf("%lu\n", htoi(argv[1]));
    }
    return 0;
}