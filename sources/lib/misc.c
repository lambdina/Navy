/*
** EPITECH PROJECT, 2019
** misc.c
** File description:
** miscellaneous functions
*/

#include "navy.h"

int my_getnbr(char const *str)
{
    int neg = 0;
    long res = 0;
    int result = 0;

    if (str[0] == '\0' || str == NULL)
        return 0;
    for (int i = 0; str[i]; i++) {
        neg = str[i] == '-' ? neg + 1 : neg;
        if ((test_if_alpha(str[i])) && res != 0)
            break;
        else if (str[i] >= '0' && str[i] <= '9')
            res = res * 10 + str[i] - 48;
    }
    result = (int)res;
    if (result != res)
        return 0;
    result = neg % 2 == 1 ? -result : result;
    return result;
}

void my_swap_int(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}

void my_swap_char(char *a, char *b)
{
    char tmp = *a;

    *a = *b;
    *b = tmp;
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

char *my_strncat(char *s1, char *s2, int n)
{
    char *result = NULL;
    int s1_len = my_strlen(s1);

    if (s1 == NULL)
        return (s2);
    else if (s2 == NULL)
        return (s1);
    result = malloc(sizeof(char) * (n + 1));
    if (result == NULL)
        return (NULL);
    for (int i = 0; i < n; i++) {
        if (i < s1_len)
            result[i] = s1[i];
        else result[i] = s2[i - s1_len];
    }
    result[n] = '\0';
    return result;
}
