/*
** EPITECH PROJECT, 2019
** counter_functions
** File description:
** random functions counting characters
*/

#include "navy.h"

int count_until_that_char(char *str, char c)
{
    int count = 0;

    if (str == NULL || str[0] == '\0')
        return (0);
    for (; str[count] != 0 && str[count] != c; count++);
    return (count);
}

int count_that_char(char *str, char that_char)
{
    int occurence = 0;

    if (str == NULL || str[0] == '\0')
        return (occurence);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == that_char)
            occurence++;
    return (occurence);
}
