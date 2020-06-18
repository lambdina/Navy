/*
** EPITECH PROJECT, 2019
** check_args
** File description:
** function that analyze the arguments
*/

#include "navy.h"

bool check_args(int argc, char **argv)
{
    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0)
            return display_usage();
    }
    else if (argc > 3 || (argc == 3 && (argv[2] == NULL || argv[2][0] == 0
    || !check_if_num(argv[1]))) || argc == 1)
        return (display_custom_usage(2));
    return (true);
}
