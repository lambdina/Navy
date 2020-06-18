/*
** EPITECH PROJECT, 2019
** tests_open_a_map
** File description:
** criterion tests handling if the return value of both open and read functions.
*/

#include "navy.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all(void);

Test(open_and_read, test_open_and_read)
{
    int size = 100;
    char *buff = malloc(sizeof(char) * size + 1);
    char *buff_2 = NULL;

    cr_assert_eq(open_and_read("./Makefile", &buff, size), 0);
    cr_assert_eq(open_and_read("lol", &buff, size), 84);
    cr_assert_eq(open_and_read("./Makefile", &buff_2, size), 84);
    cr_assert_eq(open_and_read(NULL, &buff, size), 84);
    cr_assert_eq(open_and_read("", &buff, size), 84);
}

Test(display_usage, print_display_usage, .init = redirect_all)
{
    display_usage();
}
