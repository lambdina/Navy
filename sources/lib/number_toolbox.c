/*
** EPITECH PROJECT, 2019
** number_toolbox.c
** File description:
** everything i may need to display a number
*/

#include "navy.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 0) {
        if (nb >= 10) {
            my_put_nbr(nb / 10);
            my_putchar(nb % 10 + 48);
        }
        else my_putchar(nb + 48);
    }
    return 0;
}

int my_is_prime(int nb)
{
    if (nb <= 1)
        return 0;
    for (int div = 2; div * div <= nb; div++)
        if (nb % div == 0)
            return 0;
    return 1;
}

int my_compute_square_root(int nb)
{
    int const max_root = 46341;

    if (nb <= 0)
        return 0;
    else if (nb == 1)
        return 1;
    for (int root = 1; root < max_root && root < nb; root++)
        if (root * root == nb)
            return root;
    return 0;
}

int my_find_prime_sup(int nb)
{
    for (; !my_is_prime(nb); nb++);
    return nb;
}
