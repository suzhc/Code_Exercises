#include <stdio.h>
#include <ctype.h>

#define WORDLEN 20 /* Max length of a word - not including trailing null */

void getword(char w[])
{
    int c; /* lookahead character */
    int i; /* position in word */

    /* Skip separators */

    do
    {
        c = getchar();
    } while (!isalpha(c) && !isdigit(c) && (c != EOF));

    /* Form the word */

    i = 0;
    while (isalpha(c) || isdigit(c))
    {
        w[i++] = c;
        c = getchar();
    }

    /* Put back the lookahead character for next time */
    if (c != EOF)
        ungetc(c, stdin);

    /* Terminate word with a null */
    w[i] = '\0';
}

int main(void)
{
    char word[WORDLEN + 1]; /* one word-allow extra space for final null */
    int wordcount = 0;      /* count of number of words seen */
    while (1)
    {
        getword(word);
        if (word[0] == '\0')
            break; /* End of file seen */
        printf("%s\n", word);
        wordcount++;
    }
    printf("------------------\nThere were %d words\n", wordcount);
    return 0;
}