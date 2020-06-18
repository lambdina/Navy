/*
** EPITECH PROJECT, 2019
** check_boats_intersections
** File description:
** intersections boats handling
*/

#include "navy.h"

int element_in_tab(int *big_tab, int *tab, int size_big_tab, int size_tab)
{
    int big_i = 0;
    int i = 0;

    for (; big_i < size_big_tab; big_i++)
        for (i = 0; i < size_tab; i++)
            if (big_tab[big_i] == tab[i])
                return (1);
    return (0);
}

int *fill_that_tab_with(int number, int malloc_size)
{
    int *dest = malloc(sizeof(int) * malloc_size);
    int i = 0;

    for (; i < malloc_size; dest[i] = number, i++);
    return (dest);
}

int *fill_current_boat_coordinates(char *file, int len_boat)
{
    int *dest = malloc(sizeof(int) * (len_boat + 1));
    int inc = 0;

    if (file[2] == file[5]) {
        inc = 8;
        if (file[5] - file[2] < 0)
            inc = -inc;
    }
    else {
        inc = 1;
        if (file[6] - file[3] < 0)
            inc = - inc;
    }
    dest[0] = (file[2] - 'A' + 1) + ((file[3] - '0'- 1) * 8);
    for (int j = 1; j < len_boat; dest[j] = dest[j - 1] + inc, j++);
    return (dest);
}

int check_intersections_boat(char *file)
{
    int *coordinate_list = fill_that_tab_with(-1, (2 + 3 + 4 + 5));
    int *tmp = NULL;
    int cursor = 0;
    int size_tmp = 0;

    for (int i = 0; i < 32; i += 8) {
        size_tmp = file[i] - '0';
        tmp = fill_current_boat_coordinates(&file[i], size_tmp);
        if (element_in_tab(coordinate_list, tmp, cursor, size_tmp))
            return (1);
        for (int j = 0; j < size_tmp; coordinate_list[cursor] = tmp[j],
        cursor++, j++);
        free(tmp);
    }
    free(coordinate_list);
    return (0);
}
