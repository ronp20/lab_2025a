/*
    * Created By Ron Potashnik 2024.
    * This program processes input text, formatting it according to specific rules
    * regarding capitalization, quotation handling, and digit filtering.
 */

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>  /* Required for isatty() */

/* Define a boolean type */
typedef enum BOOL_E
{
    FALSE = 0,
    TRUE = 1
} BOOL_E;

/*
    @brief Check if the input is coming from a terminal (no redirection)
    @return TRUE if the input is coming from a terminal, FALSE otherwise
*/
static BOOL_E is_terminal_input();

int main(int argc, char *argv[])
{
    char c; /* Variable to store the current character */
    BOOL_E is_new_sentence = TRUE;  /* Track if we are at the start of a new sentence */
    BOOL_E is_inside_quotes = FALSE; /* Track if we are inside quotes */

    /* Check if the input is coming from a terminal (no redirection) */
    if (is_terminal_input())
    {
        printf("Hello, Please enter the text. The program will process your input, When you are done, press Ctrl+D(Linux) or Ctrl+Z(Windows) to exit.\n\n");
    }

    /* Loop to read input until EOF */
    while ((c = getchar()) != EOF)
    {
        if (c == '"')
        {
            /* Toggle the state for quotes explicitly */
            if (is_inside_quotes)
            {
                is_inside_quotes = FALSE;  /* Now outside quotes */
            }
            else
            {
                is_inside_quotes = TRUE;   /* Now inside quotes */
            }

            if (is_new_sentence)
            {
                is_new_sentence = FALSE;  /* Reset the new sentence flag */
            }

            putchar(c);  /* Print the quote character */
        }
        else if (is_inside_quotes && isalpha(c))
        {
            putchar(toupper(c));  /* Inside quotes, convert to uppercase */
        }
        else if (is_new_sentence)
        {
            if (isalpha(c))
            {
                putchar(toupper(c));
            }
            else if (FALSE == isdigit(c))
            {
                putchar(c);
            }

            if (c != '.' && c != '\n' && c != ' ' && c != '\t')
            {
                is_new_sentence = FALSE;  /* Mark the start of a new sentence */
            }
        }
        else if (!is_inside_quotes && isalpha(c))
        {
            putchar(tolower(c));  /* Convert to lowercase outside of quotes */
        }
        else if (isdigit(c))
        {
            continue;  /* Ignore digits */
        }
        else
        {
            putchar(c);  /* Print other characters as-is */

            /* End of sentence handling */
            if (c == '.' && !is_inside_quotes)
            {
                is_new_sentence = TRUE;  /* Mark the start of a new sentence */
            }
        }
    }

    putchar('\n');  /* Print a newline at the end */
    return 0;
}

BOOL_E is_terminal_input()
{
    return (isatty(fileno(stdin)) == 1) ? TRUE : FALSE;
}