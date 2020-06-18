/*
** EPITECH PROJECT, 2019
** test_lib.c
** File description:
** functions testing librairy
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include <stddef.h>

void redirect_all(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(translate_msg_from_binary, test_transalte_msg_from_bin)
{
    char *str_test1 = my_get_nbr_base("01", 25);

    cr_assert_eq(translate_msg_from_binary(str_test1), 25);
}

Test(my_strcpy, strcpy)
{
    char *tes = malloc(sizeof(char) * 5);

    tes = my_strcpy(tes, "hello");
    cr_assert_str_eq(tes, "hello", "fail at my_strcpy");
    free(tes);
}

Test(my_strncpy, strncpy)
{
    char *res = malloc(sizeof(char) * 5);

    res = my_strncpy(res, "Hello world !", 4);
    cr_assert_str_eq(res, "Hell", "fail at my_strncpy");
    free(res);
}

Test(resize_list, resize_list)
{
    int *result = malloc(sizeof(int) * 3);

    result[0] = 3;
    result[1] = 5;
    result[2] = 8;
    result = resize_list(result, 3, true);
    cr_assert_eq(result[0], 0, "Error: resize list -> result[0]");
    cr_assert_eq(result[1], 3, "Error: resize list -> result[1]");
    cr_assert_eq(result[2], 5, "Error: resize_list -> result[2]");
    cr_assert_eq(result[3], 8, "Error: resize_list -> result[3]");
    result = resize_list(result, 4, false);
    cr_assert_eq(result[0], 3, "Error: resize_list -> result[0] (2)");
    cr_assert_eq(result[1], 5, "Error: resize_list -> result[1] (2)");
    cr_assert_eq(result[2], 8, "Error: resize_list -> result[2] (2)");
    free(result);
}

Test(my_strdup, strdup)
{
    char *result = my_strdup("fortnite");

    cr_assert_str_eq(result, "fortnite");
    free(result);
}

Test(my_realloc, realloc)
{
    char *lol = my_strdup("lol");

    lol = my_realloc(lol, 1);
    lol[3] = '6';
    cr_assert_str_eq(lol, "lol6", "Error: realloc failed");
}

Test(my_itoa, itoa)
{
    char *normal_nb = my_itoa(12);
    char *zero = my_itoa(0);

    cr_assert_str_eq(normal_nb, "12");
    cr_assert_str_eq(zero, "0");
    free(normal_nb);
    free(zero);
}

Test(my_getnbr, getnbr)
{
    cr_assert_eq(my_getnbr("666"), 666);
    cr_assert_eq(my_getnbr("-12"), -12);
    cr_assert_eq(my_getnbr("12ab3"), 12);
}

Test(my_putchar, putchar, .init = redirect_all)
{
    my_putchar('a');
    cr_assert_stdout_eq_str("a");
}

Test(my_putstr, putstr, .init = redirect_all)
{
    my_putstr("test");
    cr_assert_stdout_eq_str("test");
}

Test(my_puterror, puterror, .init = redirect_all)
{
    my_puterror("test123");
    cr_assert_stdout_eq_str("test123");
}

Test(my_strncpy_until, strncpy_until)
{
    char *test = my_strdup("fortnite");
    char *dest = malloc(sizeof(char) * (my_strlen(test) + 1));

    dest = my_strncpy_until(dest, test, 0, my_strlen(test));
    cr_assert_str_eq(dest, test);
    free(test);
    free(dest);
}

Test(my_getnbr, wrong_input_getnbr)
{
    cr_assert_eq(my_getnbr(""), 0);
}

Test(my_swap_char, swap_char, .init = redirect_all)
{
    char a = 'a';
    char b = 'b';

    my_swap_char(&a, &b);
    my_putchar(a);
    my_putchar(b);
    cr_assert_stdout_eq_str("ba");
}

Test(my_revstr, rev_str)
{
    char *result = my_revstr(my_strdup("yes"));

    cr_assert_str_eq(result, "sey");
}

Test(my_strcmp, compare_two_strings)
{
    char *one = my_strdup("i love python");
    char *two = my_strdup("i love python");
    char *wrong = my_strdup("i love c");

    cr_assert_eq(my_strcmp(one, two), 0);
    cr_assert_neq(my_strcmp(one, wrong), 0);
    free(one);
    free(two);
    free(wrong);
}

Test(set_to_lowercase, lowercase)
{
    char *fortnite = my_strdup("haha YES");

    cr_assert_str_eq(set_to_lowercase(fortnite), "haha yes");
    free(fortnite);
}

Test(set_to_uppercase, uppercase)
{
    char *fortnite = my_strdup("haha YES");

    cr_assert_str_eq(set_to_uppercase(fortnite), "HAHA YES");
    free(fortnite);
}

Test(is_superior, test_if_superior)
{
    int one = 1;
    int two = 2;

    cr_assert_eq(is_superior(1, 2), false);
}

Test(is_inferior, test_if_inferior)
{
    int one = 1;
    int two = 2;

    cr_assert_eq(is_inferior(1, 2), true);
}

Test(display_int_array, display_array, .init = redirect_all)
{
    int size = 2;
    int *arr = malloc(sizeof(int) * size);

    arr[0] = 12;
    arr[1] = 5;
    display_int_array(arr, size);
}

Test(check_if_num, test_check_if_num)
{
    char *num = my_strdup("123214");
    char *not_num = my_strdup("123ab");

    cr_assert_eq(check_if_num(num), true);
    cr_assert_eq(check_if_num(not_num), false);
    free(num);
    free(not_num);
}

Test(check_if_alphabetic, test_check_if_alphabetic)
{
    char *num = my_strdup("-123214");
    char *not_num = my_strdup("123ab");
    char *ok = my_strdup("abDedCdfSDf");

    cr_assert_eq(check_if_alphabetic(ok), true);
    free(ok);
    free(num);
    free(not_num);
}

Test(count_letters, test_letters_count)
{
    char *test = my_strdup("malloc1231asd");
    int result = count_letters(test);

    cr_assert_eq(result, 9);
    free(test);
}

Test(test_if_alpha, if_alpha)
{
    char c = 'u';
    char d = 'V';

    cr_assert_eq(test_if_alpha(c), true);
    cr_assert_eq(test_if_alpha(d), true);
}

Test(test_if_num, if_num)
{
    char c = '0';
    char d = 'a';

    cr_assert_eq(test_if_num(c), true);
    cr_assert_eq(test_if_num(d), false);
}

Test(test_if_alphanum, is_alphanum)
{
    char c = '-';
    char d = 'a';

    cr_assert_eq(test_if_alphanum(c), false);
    cr_assert_eq(test_if_alphanum(d), true);
}

Test(test_if_printable, is_printable)
{
    char c = 5;
    char d = 'd';

    cr_assert_eq(test_if_printable(d), true);
    cr_assert_eq(test_if_printable(c), false);
}

Test(my_getnbr, getnbr_neg)
{
    char *nb = my_strdup("-5257");
    char *nb2 = my_strdup("-0");
    char *nb1 = my_strdup("0");
    char *nb3 = my_strdup("--7");
    char *nb4 = my_strdup("---12");

    cr_assert_eq(my_getnbr(nb), -5257);
    cr_assert_eq(my_getnbr(nb1), 0);
    cr_assert_eq(my_getnbr(nb2), 0);
    cr_assert_eq(my_getnbr(nb3), 7);
    cr_assert_eq(my_getnbr(nb4), -12);
}

Test(count_that_char, test_count_that_char)
{
    cr_assert_eq(count_that_char(NULL, 'o'), 0);
    cr_assert_eq(count_that_char("", 'o'), 0);
    cr_assert_eq(count_that_char("         ", 'l'), 0);
    cr_assert_eq(count_that_char("bonjour mdr", 'o'), 2);
}

Test(count_until_that_char, test_count_until_that_char)
{
    cr_assert_eq(count_until_that_char("     l", 'l'), 5);
    cr_assert_eq(count_until_that_char(NULL, 'l'), 0);
    cr_assert_eq(count_until_that_char("", 'l'), 0);
}

Test(get_tab_len, test_tab_len)
{
    char **test = tabgen("this is a test", ' ');

    cr_assert_eq(get_tab_len(test), 4);
    my_show_word_array(test);
    free_tab(test);
}

Test(test_if_in_string, this_is_epic)
{
    cr_assert_eq(test_if_in_string('c', "char"), true);
    cr_assert_eq(test_if_in_string('c', NULL), false);
}

Test(my_put_nbr, test_putnbr, .init = redirect_all)
{
    my_put_nbr(-12);
    cr_assert_stdout_eq_str("-12");
}

Test(my_is_prime, test_if_prime)
{
    cr_assert_eq(my_is_prime(0), 0);
    cr_assert_eq(my_is_prime(7), 1);
}

Test(my_compute_square_root, square_root)
{
    cr_assert_eq(my_compute_square_root(-5), 0);
    cr_assert_eq(my_compute_square_root(1), 1);
    cr_assert_eq(my_compute_square_root(9), 3);
}

Test(my_find_prime_sup, find_prime_sup)
{
    cr_assert_eq(my_find_prime_sup(6), 7);
}

Test(my_getnbr, too_long_number)
{
    cr_assert_eq(my_getnbr("12383420348"), 0);
}

Test(my_swap_int, swap_int)
{
    int i = 5;
    int j = 6;

    my_swap_int(&i, &j);
    cr_assert_eq(i, 6);
    cr_assert_eq(j, 5);
}

Test(my_strncat, strncat_test)
{
    cr_assert_str_eq(my_strncat(NULL, "test", 5), "test");
    cr_assert_str_eq(my_strncat("test", NULL, 5), "test");
    cr_assert_str_eq(my_strncat("lol", " haha", 5), "lol h");
}

Test(clean_str, cleaning_up)
{
    cr_assert_eq(check_if_in_string('/', "/dev"), true);
    cr_assert_str_eq(get_last_occurence_of('/', "home/bguillem/test"), "test");
}
