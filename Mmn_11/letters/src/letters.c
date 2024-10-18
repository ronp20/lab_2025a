/*
    * Created By Ron Potashnik 2024.
    * This program processes input text, formatting it according to specific rules
    * regarding capitalization, quotation handling, and digit filtering.
 */

#include "my_std.h"

int main(int argc, char *argv[])
{
    char c;
    BOOL new_sentence = TRUE;  /* Track if we are at the start of a new sentence */
    BOOL inside_quotes = FALSE; /* Track if we are inside quotes */

    printf("Hello, Please enter the text. The program will process your input, When you are done, press Ctrl+D(Linux) or Ctrl+Z(Windows) to exit.\n\n");

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
        else if (inside_quotes && my_isalpha(c))
        {
            putchar(my_toupper(c));  /* Inside quotes, convert to uppercase */
        }
        else if (new_sentence)
        {
            if (my_isalpha(c))
            {
                putchar(my_toupper(c));
            }
            else if (FALSE == my_isdigit(c))
            {
                putchar(c);
            }

            if (c != '.' && c != '\n' && c != ' ' && c != '\t')
            {
                new_sentence = FALSE;  /* Mark the start of a new sentence */
            }
        }
        else if (!inside_quotes && my_isalpha(c))
        {
            putchar(my_tolower(c));  /* Convert to lowercase outside of quotes */
        }
        else if (my_isdigit(c))
        {
            continue;  /* Ignore digits */
        }
        else
        {
            putchar(c);  /* Print other characters as-is */

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
