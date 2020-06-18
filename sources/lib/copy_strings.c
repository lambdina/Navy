/*
** EPITECH PROJECT, 2019
** copy_strings.c
** File description:
** functions needed to copy a string
*/

#include "navy.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (src == NULL)
        return (NULL);
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (src == NULL)
        return (NULL);
    for (; src[i] && i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strncpy_until(char *dest, char const *src, int from, int until)
{
    int i = from;

    if (src == NULL)
        return NULL;
    for (int j = 0; src[i] && j < until; i++, j++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
