/*
 * Created By Ron Potashnik 2024.
 */

#include "my_bitwise.h"

#define BYTE_SIZE 8
#define ULONG_SIZE sizeof(unsigned long) * BYTE_SIZE

unsigned long set_bit(unsigned long num, unsigned long pos)
{
    return num | (1 << pos);
}

BOOL_E is_bit_set(unsigned long num, unsigned long pos)
{
    return ((num & (1 << pos)) != 0) ? TRUE : FALSE;
}

void print_binary(unsigned long n)
{
    int i = ULONG_SIZE - 1;
    for (; i >= 0; i--)
    {
        printf("%lu", (n >> i) & 1);
        if (i % 4 == 0)
        {
            printf(" ");  /* Spacing every 4 bits for readability */
        }
    }
    printf("\n");
}