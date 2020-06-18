/*
** EPITECH PROJECT, 2019
** tabgen.c
** File description:
** creates a char ** according to a defined separator
*/

#include "navy.h"

char **tabgen(char *str, char separator)
{
    int i = 0;
    int malloc_size = 0;
    int index_str = 0;
    char **res = malloc(sizeof(char *) * (get_nb_rows(str, separator) + 2));

    if (str == NULL || str[0] == '\0')
        return NULL;
    for (; i < get_nb_rows(str, separator); i++) {
        malloc_size = get_nb_cols(str, index_str, separator);
        res[i] = malloc(sizeof(char) * (malloc_size + 1));
        res[i] = my_strncpy(res[i], &str[index_str], malloc_size);
        index_str = index_str + malloc_size + 1;
    }
    res[i] = NULL;
    return res;
}

int get_nb_cols(char *str, int n, char separator)
{
    int i = n;
    int res = 0;

    if (str == NULL || str[0] == '\0')
        return 0;
    for (; str[i] != '\0' && str[i] != separator; i++, res++);
    return res;
}

int get_nb_rows(char *str, char separator)
{
    int i;
    int res = 0;

    if (str == NULL || str[0] == '\0')
        return 0;
    if (str == NULL || str[0] == '\0')
        return (0);
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == separator)
            res++;
    return res + 1;
}
