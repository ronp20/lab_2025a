/*
 * Created By Ron Potashnik 2024.
 */

#include "my_std.h"

int my_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - ('a' - 'A');
    }

    return c;
}

int my_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + ('a' - 'A');
    }

    return c;
}

BOOL my_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) ? TRUE : FALSE;
}

BOOL my_isdigit(int c)
{
    return (c >= '0' && c <= '9') ? TRUE : FALSE;
}
