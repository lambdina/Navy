/*
** EPITECH PROJECT, 2019
** malloc_toolbox.c
** File description:
** useful functions using malloc
*/

#include "navy.h"

char *my_strdup(char const *str)
{
    char *result = NULL;

    if (str == NULL || str[0] == '\0')
        return NULL;
    result = malloc(sizeof(char) * (my_strlen(str) + 1));
    result = my_strcpy(result, str);
    return result;
}

char *my_strcat(char *s1, char const *s2)
{
    char *result;
    int i = 0;

    if (s1 == NULL || s1[0] == '\0')
        return (my_strdup(s2));
    else if (s2 == NULL || s2[0] == '\0')
        return (my_strdup(s1));
    result = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    for (; s1[i] != '\0'; i++)
        result[i] = s1[i];
    for (int j = 0; s2[j] != '\0'; j++, i++)
        result[i] = s2[j];
    result[i] = '\0';
    return (result);
}

char *my_realloc(char *src, int size)
{
    int total_size = my_strlen(src) + size;
    char *result = malloc(sizeof(char) * (total_size + 1));
    int i = 0;

    for (; src[i]; i++)
        result[i] = src[i];
    for (; i <= total_size; i++)
        result[i] = '\0';
    free(src);
    return result;
}

int get_len_nb(int nb)
{
    int i;

    if (nb == 0)
        return 1;
    nb = nb < 0 ? nb * -1 : nb;
    for (i = 0; nb != 0; i++, nb = nb / 10);
    return i;
}

char *my_itoa(int nb)
{
    int len = get_len_nb(nb);
    char *result = malloc(sizeof(char) * (len + 1));
    int i = len - 1;
    bool negative = nb < 0 ? true : false;

    for (; i >= 0; i--, nb = nb / 10)
        result[i] = (nb % 10) + 48;
    result[len] = '\0';
    return negative == true ? my_strcat("-", result) : result;
}
