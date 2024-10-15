/*
 * Created By Ron Potashnik 2024.
 */

/*
    This header file contains declarations for functions that are similar to the standard library functions.
*/

#ifndef MY_STD_H
#define MY_STD_H

#include <stdio.h>

typedef int BOOL;  /* Define BOOL as an alias for int */
#define TRUE 1
#define FALSE 0

/*
    @brief  Convert a character to uppercase.
    @param  c  The character to convert.
    @return  The uppercase character.
*/
int my_toupper(int c);

/*
    @brief  Convert a character to lowercase.
    @param  c  The character to convert.
    @return  The lowercase character.
*/
int my_tolower(int c);

/*
    @brief  Check if a character is alphabetic.
    @param  c  The character to check.
    @return  TRUE if the character is alphabetic, otherwise FALSE.
*/
BOOL my_isalpha(int c);

/*
    @brief  Check if a character is a digit.
    @param  c  The character to check.
    @return  TRUE if the character is a digit, otherwise FALSE.
*/
BOOL my_isdigit(int c);

#endif  /* MY_STD_H */