/*
** EPITECH PROJECT, 2019
** tests_valid_map
** File description:
** criterion tests for error gestion of the map given as parameter
*/

#include <criterion/criterion.h>
#include "navy.h"

void redirect_all();

Test(abs, test_abs)
{
    cr_assert_eq(abs(2), 2);
    cr_assert_eq(abs(-1), 1);
}

Test(check_pattern, test_check_pattern)
{
    cr_assert_eq(check_pattern("2:C4:C5\n", 0), 0);
    cr_assert_eq(check_pattern("2:C4:C5\t", 0), 1);
    cr_assert_eq(check_pattern("2:c4:C5\n", 0), 1);
    cr_assert_eq(check_pattern("2:CC:C5\n", 0), 1);
    cr_assert_eq(check_pattern("2;C4:C5\n", 0), 1);
    cr_assert_eq(check_pattern("2:C4:C5\n", 8), 1);
}

Test(check_out_of_range, test_check_out_of_range)
{
    cr_assert_eq(check_out_of_range("2:C4:C5\n", 0), 0);
    cr_assert_eq(check_out_of_range("2:C4:C6\n", 0), 1);
    cr_assert_eq(check_out_of_range("2:D4:E4\n", 0), 0);
    cr_assert_eq(check_out_of_range("2:D4:E6\n", 0), 1);
    cr_assert_eq(check_out_of_range("2:C4:C9\n", 0), 1);
    cr_assert_eq(check_out_of_range("2:Z4:C4\n", 0), 1);
    cr_assert_eq(check_out_of_range("2:Z4:Z4\n", 0), 1);
    cr_assert_eq(check_out_of_range("2:C4:C5\n", 8), 1);
    cr_assert_eq(check_out_of_range("2:C9:D9\n", 0), 1);
}

Test(check_map, test_check_map)
{
    cr_assert_eq(check_map("2:C1:C2\n3:D4:F4\n4:B5:B8\n5:D7:H7\n"), 0);
    cr_assert_eq(check_map("mdr"), 84);
    cr_assert_eq(check_map("4:C1:C2\n3:D4:F4\n4:B5:B8\n5:D7:H7\n"), 84);
    cr_assert_eq(check_map("2:C1:C2\n3:D4:F4\n4:B5:B8\n5:D7:H7"), 0);
    cr_assert_eq(check_map("2:C1:C2l\n3:D4:F4\n4:B5:B8\n5:D7:H7\n"), 84);
    cr_assert_eq(check_map("2:C1/C2\n3:D4:F4\n4:B5:B8\n5:D7:H7\n"), 84);
    cr_assert_eq(check_map("2:Z1:C2\n3:D4:F4\n4:B5:B8\n5:D7:H7\n"), 84);

}

Test(main_error_gestion, test_main_error_gestion)
{
    cr_assert_eq(main_error_gestion("mdr"), false);
    cr_assert_eq(main_error_gestion("./Makefile"), false);
}

Test(element_in_tab, test_element_in_tab)
{
    int big_tab[10] = {0, 1, 2, 3, 4, 5, 6};
    int tab_1[2] = {5, 6};
    int tab_2[2] = {5, 15};
    int tab_3[2] = {12, 12};

    cr_assert_eq(element_in_tab(big_tab, tab_1, 10, 2), 1);
    cr_assert_eq(element_in_tab(big_tab, tab_2, 10, 2), 1);
    cr_assert_eq(element_in_tab(big_tab, tab_3, 10, 2), 0);
    cr_assert_eq(element_in_tab(NULL, NULL, 0, 0), 0);
}

Test(fill_that_tab_with, test_fill_that_tab_with)
{
    int *tab = malloc(sizeof(int) * 10);

    tab = fill_that_tab_with(-1, 10);
    for (int i = 0; i < 10; i++)
        cr_assert_eq(tab[i], -1);
}

Test(fill_current_boat_coordinates, test_fill_cur_coordinates)
{
    int *tab_result = fill_current_boat_coordinates("2:C1:C2\n", 2);

    cr_assert_eq(tab_result[0], 3);
    cr_assert_eq(tab_result[1], 11);
    cr_assert_neq(tab_result[0], 11);
    cr_assert_neq(tab_result[1], 19);
}

Test(check_intersections_boat, test_check_intersection_boat)
{
    cr_assert_eq(
    check_intersections_boat("2:C1:C2\n3:D4:F4\n4:B5:B8\n5:D7:H7\n"), 0);
    cr_assert_eq(
    check_intersections_boat("2:B5:B6\n3:D4:F4\n4:B5:B8\n5:D7:H7\n"), 1);
}

Test(check_args, test_check_args, .init = redirect_all)
{
    char **test_1 = tabgen("./navy -h ", ' ');
    char **test_2 = tabgen("./navy -hlol", ' ');
    char **test_3 = tabgen( "./navy", ' ');
    char **test_4 = tabgen("./navy 2322 2233 lol", ' ');
    char **test_5 = tabgen("./navy 4444", ' ');
    char **test_6 = tabgen("./navy filepath 4335", ' ');
    char **test_7 = tabgen("./navy 4444 filepath", ' ');
    char **test_8 = tabgen("./navy 3333 3h3", ' ');

    cr_assert_eq(check_args(2, test_1), false);
    cr_assert_eq(check_args(2, test_2), true);
    cr_assert_eq(check_args(1, test_3), false);
    cr_assert_eq(check_args(4, test_4), false);
    cr_assert_eq(check_args(2, test_5), true);
    cr_assert_eq(check_args(3, test_6), false);
    cr_assert_eq(check_args(3, test_7), true);
    cr_assert_eq(check_args(3, test_8), true);
}
