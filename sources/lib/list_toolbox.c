/*
** EPITECH PROJECT, 2019
** list_toolbox.c
** File description:
** functions resizing list properly, etc
*/

#include "navy.h"

int *resize_list(int *list, int size, bool plus_one)
{
    int *result;
    int to_add = plus_one == true ? 1 : -1;
    int j = plus_one == true ? 0 : 1;

    result = malloc(sizeof(int) * (size + to_add + 1));
    for (int i = plus_one; i < size + to_add; i++, j++)
        result[i] = list[j];
    result[0] = plus_one == true ? 0 : result[0];
    free(list);
    return result;
}

bool is_superior(int n1, int n2)
{
    return n1 >= n2 ? true : false;
}

bool is_inferior(int n1, int n2)
{
    return n1 <= n2 ? true : false;
}

void display_int_array(int *arr, int size)
{
    for (int i = 0; i < size; i++) {
        my_put_nbr(arr[i]);
        my_putchar(' ');
    }
    my_putchar('\n');
}
