/** @file word_count.c
 *  @brief Implementation for Exercise 1-11.
 *  
 *  Exercise 1-11. How would you test the word count program?
 *  What kinds of input are most likely to uncover bugs if there are any?
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>

/** @brief A function that counts characters, words and lines in the stdin file.
 *  @return Void.
*/
void word_count(void)
{
    unsigned int lines = 0, characters = 0, words = 0;
    char state = 0;
    int c = '\0';
        while((c = getchar()) != EOF)
        {
            if(c == '\n')
            {
                lines++, state = 0;
            }
            else if(c == ' ' || c == '\t')
            {
                state = 0;
            }
            else
            {
                characters++;
                if(state == 0) words++, state = 1;
            }
    }
    printf("Words: %u\tCharacters: %u\t\tLines: %u\n", words, characters, lines);
}

//To signal an EOF in terminal, used CTRL-D
int main()
{
    word_count();
    return 0;
}