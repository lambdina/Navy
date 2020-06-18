/*
** EPITECH PROJECT, 2019
** check_map
** File description:
** error gestion for map send in parameter.
*/

#include "navy.h"

int abs(int nb)
{
    return (nb < 0 ? -nb : nb);
}

int check_pattern(char *map, int advancement)
{
    int len_board = (advancement / 8) + 2;

    if (map[0] - '0' != len_board || char_is_upper(map[2]) == false
    || char_is_upper(map[5]) == false || test_if_num(map[3]) == false
    || test_if_num(map[6]) == false)
        return (1);
    else if (map[1] != ':' || map[4] != ':' || (map[7] != '\n' &&
    map[7] != 0))
        return (1);
    return (0);
}

int check_out_of_range(char *map, int advancement)
{
    int len_board = (advancement / 8) + 2;
    int difference = 0;

    if (map[2] == map[5]) {
        if (map[2] > 'H')
            return (1);
        difference = (abs(map[6] - map[3])) + 1;
    }
    else if (map[3] == map[6]) {
        if (map[3] < '1' || map[3] > '8')
            return (1);
        difference = (abs(map[5] - map[2])) + 1;
    }
    else return (1);
    if (difference != len_board)
        return (1);
    return (0);
}

int check_map(char *map)
{
    int total_size = 8 * 4;
    int nbr_lines = 0;
    int len = 0;

    if (map == NULL || map[0] == '\0')
        return (false);
    nbr_lines = count_that_char(map, '\n');
    len = my_strlen(map);
    if (nbr_lines < 3 || (len != total_size && len != total_size - 1))
        return (84);
    for (int cursor = 0; cursor < total_size - 1; cursor += 8) {
        if (count_until_that_char(&map[cursor], '\n') != 7)
            return (84);
        else if (check_pattern(&map[cursor], cursor) ||
        check_out_of_range(&map[cursor], cursor))
            return (84);
    }
    return (0);
}
