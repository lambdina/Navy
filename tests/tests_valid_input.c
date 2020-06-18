/*
** EPITECH PROJECT, 2019
** tests_valid_input
** File description:
** tests for functions: aims to determine either if an input is valid or not
*/

#include "navy.h"
#include <criterion/criterion.h>

Test(check_wrong_input_pattern, test_wrong_input_pattern)
{
    cr_assert_eq(check_wrong_input_pattern((int *){2, 1}), false);
    cr_assert_eq(check_wrong_input_pattern((int *){0, 1}), true);
    cr_assert_eq(check_wrong_input_pattern((int *){1, 0}), true);
    cr_assert_eq(check_wrong_input_pattern((int *){8, 2}), true);
    cr_assert_eq(check_wrong_input_pattern((int *){2, 8}), true);
    cr_assert_eq(check_wrong_input_pattern(NULL), false);
    cr_assert_eq(check_wrong_input_pattern((int *){-5, 2}), false);
}
