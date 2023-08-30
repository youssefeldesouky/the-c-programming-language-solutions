/** @file escape.c
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
 *         replacing escape sequences into their literal form.
 *  @param s The destination string that will contain literal escape sequences.
 *  @param t The source string that contains the string to be read.
 *  @return void
*/
void escape(char *s, const char *t){
    size_t i = 0, j = 0;
    while(t[i]){
        switch(t[i]){
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\v':
                s[j++] = '\\';
                s[j++] = 'v';
                break;
            case '\"':
                s[j++] = '\\';
                s[j++] = '\"';
                break;
            case '\'':
                s[j++] = '\\';
                s[j++] = '\'';
                break;
            case '\r':
                s[j++] = '\\';
                s[j++] = 'r';
                break;
            case '\f':
                s[j++] = '\\';
                s[j++] = 'f';
                break;
            case '\a':
                s[j++] = '\\';
                s[j++] = 'a';
                break;
            case '\b':
                s[j++] = '\\';
                s[j++] = '\b';
                break;
            case '\\':
                s[j++] = '\\';
                s[j++] = '\\';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }
    s[j] = '\0';
}

int main(){
    char dest[MAXLEN] = "";
    escape(dest, "hello\nworld\t\a\f\v\\\'\"");
    puts(dest);
    return 0;
}