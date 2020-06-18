/*
** EPITECH PROJECT, 2019
** clean_str.c
** File description:
** cleans a string and other misc functions
*/

#include "navy.h"

char *remove_tab(char *result)
{
    for (int i = 0; result[i] != '\0'; i++)
        if (result[i] == '\t')
            result[i] = ' ';
    return result;
}

bool check_if_in_string(char to_find, char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == to_find)
            return true;
    return false;
}

char *get_last_occurence_of(char to_find, char *s)
{
    if (check_if_in_string(to_find, &s[1]) == false)
        return s;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == to_find)
            return get_last_occurence_of(to_find, &s[i + 1]);
    return s;
}
