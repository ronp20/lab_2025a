/*
    * Created By Ron Potashnik 2024.
    * This program demonstrates bitwise operations on unsigned long integers.
    * The program sets the 13th bit in an unsigned long number and checks if the 7th bit is set in another number.
 */

#include "my_bitwise.h"

int main()
{
    unsigned long x, y; /* Input values */
    BOOL y_bit_6_status; /* Status of the 7th bit in y */
    BOOL x_bit_12_status; /* Status of the 13th bit in x */

    /* Request input */
    printf("Enter value for x (unsigned long): ");
    scanf("%lu", &x);
    printf("Enter value for y (unsigned long): ");
    scanf("%lu", &y);

    /* Print input values in both unsigned long and binary format */
    printf("\nInitial values:\n");
    printf("x = %lu (binary: ", x);
    print_binary(x);
    printf("y = %lu (binary: ", y);
    print_binary(y);

    x_bit_12_status = is_bit_set(x, 12);
    if (x_bit_12_status)
    {
        printf("\nThe 13th bit in x is already set (bit 12).\n");
    }
    else
    {
        printf("\nModified x (13th bit set):\n");
        x = set_bit(x, 12);
    }

    printf("x = %lu (binary: ", x);
    print_binary(x);

    y_bit_6_status = is_bit_set(y, 6);

    printf("\nIs the 7th bit in y set (bit 6)? %s\n", y_bit_6_status ? "YES" : "NO");

    return 0;
}
