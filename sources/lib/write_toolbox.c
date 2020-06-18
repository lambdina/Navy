/*
** EPITECH PROJECT, 2019
** write_toolbox.c
** File description:
** basic functions using write
*/

#include "navy.h"

int get_tab_len(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return 0;
    for (; tab[i] != NULL; i++);
    return i;
}

void my_putchar(char c)
{
    if (write(1, &c, 1) == -1)
        return;
}

void my_putstr(char const *s)
{
    if (write(1, s, my_strlen(s)))
        return;
}

void my_puterror(char const *s)
{
    if (write(1, s, my_strlen(s)))
        return;
}

void my_show_word_array(char * const * tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
