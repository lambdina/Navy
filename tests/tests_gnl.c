/*
** EPITECH PROJECT, 2019
** tests_gnl.c
** File description:
** unit tests get_next_line.c
*/

#include "get_next_line.h"
#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

Test(get_size, test_get_size)
{
    cr_assert_eq(get_size("this is a test", '\0'), 14);
    cr_assert_eq(get_size("this is a test", ' '), 4);
    cr_assert_eq(get_size("", '\n'), 0);
    cr_assert_eq(get_size("\nlol", '\n'), 1);
    cr_assert_eq(get_size("\0", '\0'), 0);
}

Test(copy_until, test_copy_until)
{
    cr_assert_str_eq(copy_until("this is string", ' ', 5), "is");
    cr_assert_str_eq(copy_until("this is a", '\0', 0), "this is a");
    cr_assert_eq(copy_until("", '\n', 2), 0);
    cr_assert_str_eq(copy_until("\nbonjour", '\n', 0), "\0");
}

Test(rest_got_a_line, test_rest_got_a_line)
{
    cr_assert_eq(rest_got_a_line("no line here"), false);
    cr_assert_eq(rest_got_a_line("line\nhere\n"), true);
    cr_assert_eq(rest_got_a_line(""), false);
}

Test(get_next_line, test_gnl_failure)
{
    int fd = open("fortnite", O_RDONLY);

    cr_assert_eq(get_next_line(fd), 0);
    close(fd);
}

Test(get_next_line, test_gnl)
{
    int fd = open("Makefile", O_RDONLY);

    cr_assert_str_eq(get_next_line(fd), "##");
    cr_assert_str_eq(get_next_line(fd), "## EPITECH PROJECT, 2019");
    cr_assert_str_eq(get_next_line(fd), "## Makefile");
    cr_assert_str_eq(get_next_line(fd), "## File description:");
    cr_assert_str_eq(get_next_line(fd), "## Makefile");
    cr_assert_str_eq(get_next_line(fd), "##");
    close(fd);
}
