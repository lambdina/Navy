/*
** EPITECH PROJECT, 2019
** test_string_toolbox.c
** File description:
** functions returning booleans testing a string
*/

#include "navy.h"

bool check_if_num(char const *str)
{
    if (str == NULL || str[0] == 0)
        return false;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}

bool check_if_alphabetic(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 'A' && str[i] > 'z') || (str[i] >= 91 && str[i] <= 96))
            return false;
    return true;
}

int count_letters(char const *str)
{
    int i = 0;
    int res = 0;

    for (; str[i]; i++)
        if (test_if_alpha(str[i]) == true)
            res++;
    return res;
}

bool char_is_lower(char c)
{
    return c >= 'a' && c <= 'z' ? true : false;
}

bool char_is_upper(char c)
{
    return c >= 'A' && c <= 'Z' ? true : false;
}
