/*
** EPITECH PROJECT, 2019
** string_toolbox.c
** File description:
** functions that work with strings
*/

#include "navy.h"

int my_strlen(char const *s)
{
    int i = 0;

    if (s == NULL || s[0] == '\0')
        return 0;
    for (; s[i] != '\0'; i++);
    return i;
}

char *my_revstr(char *s)
{
    int len_s = my_strlen(s);
    char temp;

    for (int i = 0, j = len_s - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return s;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] && s2[i] && s1[i] == s2[i]; i++);
    return s1[i] - s2[i];
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return 0;
    for (; s1[i] && s2[i] && (s1[i] == s2[i]) && i < n; i++);
    return s1[i] - s2[i];
}
