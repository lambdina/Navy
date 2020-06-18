/*
** EPITECH PROJECT, 2019
** test_char_toolbox.c
** File description:
** booleans testing values
*/

#include "navy.h"

bool test_if_in_string(char c, char *s)
{
    if (s == NULL || s[0] == '\0')
        return false;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            return true;
    return false;
}

bool test_if_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    return c >= 'A' && c <= 'Z' ? true : false;
}

bool test_if_num(char c)
{
    return c >= '0' && c <= '9' ? true : false;
}

bool test_if_alphanum(char c)
{
    return test_if_num(c) || test_if_alpha(c) ? true : false;
}

bool test_if_printable(char c)
{
    return c >= 32 && c <= 126 ? true : false;
}
