#include <stdio.h>
#include <ctype.h>

typedef int BOOL;  /* Define BOOL as an alias for int */
#define TRUE 1
#define FALSE 0

int main() 
{
    char c;
    BOOL new_sentence = TRUE;  /* Track if we are at the start of a new sentence */
    BOOL inside_quotes = FALSE; /* Track if we are inside quotes */

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
            putchar(c);  /* Print the quote character */
        } 
        else if (new_sentence && isalpha(c)) 
        {
            putchar(toupper(c));  /* Convert to uppercase at the start of a sentence */
            new_sentence = FALSE;  /* Reset the new sentence flag */
        } 
        else if (inside_quotes && isalpha(c)) 
        {
            putchar(toupper(c));  /* Inside quotes, convert to uppercase */
        } 
        else if (!inside_quotes && isalpha(c)) 
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
            if (c == '.' || c == '!' || c == '?') 
            {
                new_sentence = TRUE;  /* Mark the start of a new sentence */
            }
        }
    }

    return 0;
}
