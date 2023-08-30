/** @file rev_escape.c
 *  @brief Implementation for Exercise 3-2.
 * 
 *  Write a function escape(s,t) that converts characters like
 *  newline and tab into visible escape sequences like \n and \t
 *  as it copies the string t to s. Use a switch. Write a function
 *  for the other direction as well, converting escape sequences 
 *  into the real characters.
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <string.h>

//Defines the maximum length of a line
#define MAXLEN 1000

/** @brief Copies characters between character arrays up to a maxmimum length 
 *  @param dest The Destination (Copied to) Array
 *  @param src The Source (Copied from) Array
 *  @param len The maximum Length of a string
 *  @return void
*/
void copy_str(char dest[], char src[], size_t len){
    for(size_t i = 0; i < len && src[i] != '\0'; i++){
        dest[i] = src[i];
    }
}

/** @brief A function that copies characters from a string to another
 *         replacing literal escape sequences into their escape form.
 *  @param s The destination string that will contain escape sequences.
 *  @param t The source string that contains the string to be read.
 *  @return void
*/
void rev_escape(char *s, const char *t){
    size_t i = 0, j = 0;
    while(t[i]){
        if(t[i] == '\\'){
            switch (t[++i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                case 'a':
                    s[j++] = '\a';
                    break;
                case 'b':
                    s[j++] = '\b';
                    break;
                case 'v':
                    s[j++] = '\v';
                    break;
                case 'f':
                    s[j++] = '\f';
                    break;
                case 'r':
                    s[j++] = '\r';
                    break;
                case '\\':
                    s[j++] = '\\';
                    break;
                case '\'':
                    s[j++] = '\'';
                    break;
                case '\"':
                    s[j++] = '\"';
                    break;
                default:
                    s[j++] = '\\';
                    break;
            }
            i++;
        }else{
            s[j++] = t[i++];
        }
    }
    s[j] = '\0';
}

int main(){
    char dest[MAXLEN] = "";
    rev_escape(dest, "hello\\nworld\\t\\a\\f\\v\\\\'\\\"");
    puts(dest);
    return 0;
}