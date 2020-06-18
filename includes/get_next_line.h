/*
** EPITECH PROJECT, 2019
** get_next_line.h
** File description:
** get_next_line header
*/

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

char *get_next_line(int);
bool rest_got_a_line(char *);
char *concat_str(char *, char *);
char *copy_until(char *, char, int);
int get_size(char *, char);

#endif /* GET_NEXT_LINE_H */

#ifndef READ_SIZE
#define READ_SIZE (60)
#endif /* READ_SIZE */
