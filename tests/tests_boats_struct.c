/*
** EPITECH PROJECT, 2019
** tests_boats_struct
** File description:
** tests boats structure handling
*/

#include <criterion/criterion.h>
#include "navy.h"

Test(get_boats_position, test_fill_struct)
{
    boat_t *boats = get_boats_position(my_strdup
    ("2:C1:C2\n3:D4:F4\n4:B5:B8\n5:D7:H7\n"));

    cr_assert_eq(boats[0].size, 2);
    cr_assert_eq(boats[0].start_xy[0], 2);
    cr_assert_eq(boats[0].start_xy[1], 0);
    cr_assert_eq(boats[0].end_xy[0], 2);
    cr_assert_eq(boats[0].end_xy[1], 1);
    cr_assert_eq(boats[0].horizontal, true);
    cr_assert_eq(boats[1].size, 3);
    cr_assert_eq(boats[1].start_xy[0], 3);
    cr_assert_eq(boats[1].start_xy[1], 3);
    cr_assert_eq(boats[1].end_xy[0], 5);
    cr_assert_eq(boats[1].end_xy[1], 3);
    cr_assert_eq(boats[1].horizontal, false);
    free_boats_struct(boats);
}
