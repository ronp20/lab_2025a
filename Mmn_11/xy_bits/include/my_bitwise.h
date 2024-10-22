/*
 * Created By Ron Potashnik 2024.
 */

#ifndef MY_BITWISE_H
#define MY_BITWISE_H

#include <stdio.h>

/* Define a boolean type */
typedef enum BOOL_E
{
    FALSE = 0,
    TRUE = 1
} BOOL_E;

/*
    @brief  Set a bit at a specific position in a number.
    @param  num  The number to set the bit in.
    @param  pos  The position of the bit to set.
    @return  The number with the bit set.
*/
unsigned long set_bit(unsigned long num, unsigned long pos);

/*
    @brief  Check if a bit is set at a specific position in a number.
    @param  num  The number to check the bit in.
    @param  pos  The position of the bit to check.
    @return  TRUE if the bit is set, otherwise FALSE.
*/
BOOL_E is_bit_set(unsigned long num, unsigned long pos);

/*
    @brief  Print a number in binary format.
    @param  n  The number to print in binary.
*/
void print_binary(unsigned long n);

#endif  /* MY_BITWISE_H */