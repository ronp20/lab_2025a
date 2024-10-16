/*
 * Created By Ron Potashnik 2024.
 */

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>  /* Required for isatty() */

typedef int BOOL;  /* Define BOOL as an alias for int */
#define TRUE 1
#define FALSE 0

int main()
{
    char c;
    BOOL new_sentence = TRUE;  /* Track if we are at the start of a new sentence */
    BOOL inside_quotes = FALSE; /* Track if we are inside quotes */

    /* Check if the input is coming from a terminal (no redirection) */
    if (isatty(fileno(stdin)))
    {
        printf("Hello, Please enter the text. The program will process your input:\n When you are done, press Ctrl+D(Linux) or Ctrl+Z(Windows) to exit.\n\n");
    }
    else
    {
        printf("Processing input...\n\n");
    }

    /* Loop to read input until EOF */
    while ((c = getchar()) != EOF)
    {
        if (c == '"')
        {
            /* Toggle the state for quotes explicitly */
            if (inside_quotes == TRUE)
            {
                inside_quotes = FALSE;  /* Now outside quotes */
            }
            else
            {
                inside_quotes = TRUE;   /* Now inside quotes */
            }

            if (new_sentence == TRUE)
            {
                new_sentence = FALSE;  /* Reset the new sentence flag */
            }

            putchar(c);  /* Print the quote character */
        }
        else if (inside_quotes && isalpha(c))
        {
            putchar(toupper(c));  /* Inside quotes, convert to uppercase */
        }
        else if (new_sentence && isalpha(c))
        {
            putchar(toupper(c));  /* Convert to uppercase at the start of a sentence */
            new_sentence = FALSE;  /* Reset the new sentence flag */
        }
        else if (!inside_quotes && isalpha(c))
        {
            putchar(tolower(c));  /* Convert to lowercase outside of quotes */
        }
        else if (isdigit(c))
        {
            if (new_sentence == TRUE)
            {
                new_sentence = FALSE;  /* Reset the new sentence flag */
            }

            continue;  /* Ignore digits */
        }
        else
        {
            putchar(c);  /* Print other characters as-is */

            if (c != ' ' && new_sentence == TRUE)
            {
                new_sentence = FALSE;  /* Reset the new sentence flag */
            }

            /* End of sentence handling */
            if (c == '.' && inside_quotes == FALSE)
            {
                new_sentence = TRUE;  /* Mark the start of a new sentence */
            }
        }
    }

    putchar('\n');  /* Print a newline at the end */
    return 0;
}
