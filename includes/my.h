/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** libmy header
*/

#ifndef MY_H_
#define MY_H_

#include <stdbool.h>
#include <stddef.h>

// my_get_nbr_base.c
int my_pow(int, int);
int translate_msg_from_binary(char *);
char *my_get_nbr_base(char *, int);

// write_toolbox.c
void my_putchar(char);
void my_putstr(char const *);
void my_puterror(char const *);
void my_show_word_array(char * const *);
int get_tab_len(char **);

// string_toolbox.c
int my_strlen(char const *);
char *my_revstr(char *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);

// string_toolbox2.c
char *set_to_lowercase(char *);
char *set_to_uppercase(char *);

// copy_strings.c
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_strncpy_until(char *, char const *, int, int);

// number_toolbox.c
int my_put_nbr(int);
int my_is_prime(int);
int my_compute_square_root(int);
int my_find_prime_sup(int);

// malloc_toolbox.c
char *my_strdup(char const *);
char *my_strcat(char *, char const *);
char *my_realloc(char *, int);
char *my_itoa(int);
int get_len_nb(int);

// misc.c
int my_getnbr(char const *);
void my_swap_int(int *, int *);
void my_swap_char(char *, char *);
void free_tab(char **);
char *my_strncat(char *, char *, int);

// test_string_toolbox.c
bool check_if_num(char const *str);
bool check_if_alphabetic(char const *str);
int count_letters(char const *);
bool char_is_upper(char);
bool char_is_lower(char);

// test_char_toolbox.c
bool test_if_alpha(char);
bool test_if_num(char);
bool test_if_alphanum(char);
bool test_if_printable(char);
bool test_if_in_string(char, char *);

// tabgen.c
char **tabgen(char *, char);
int get_nb_cols(char *, int, char);
int get_nb_rows(char *, char);

// mini_printf.c
void mini_printf(char const *, char *);
void switch_cases(char, char *);

// list_toolbox.c
int *resize_list(int *, int, bool);
bool is_superior(int, int);
bool is_inferior(int, int);
void display_int_array(int *, int);
void test_swap_str(char **, char **);

// clean_str.c
char *remove_tab(char *);
bool check_if_in_string(char, char *);
char *get_last_occurence_of(char, char *);

// tabgen_input.c
char **tabgen_input(char *, char);
int get_next_word(char *);
int get_nb_rows_input(char *, char);

// random_functions.c
char *create_string_of_size(int);

// counter_function.c
int count_until_that_char(char *, char);
int count_that_char(char *, char);

#endif /* MY_H */
