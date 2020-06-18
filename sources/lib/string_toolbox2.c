/*
** EPITECH PROJECT, 2019
** string_toolbox2.c
** File description:
** toolbox to modify strings
*/

#include "navy.h"

char *set_to_lowercase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (char_is_upper(str[i]) == true)
            str[i] = str[i] + 32;
    return str;
}

char *set_to_uppercase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (char_is_lower(str[i]) == true)
            str[i] = str[i] - 32;
    return str;
}
