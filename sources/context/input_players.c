/*
** EPITECH PROJECT, 2019
** input_players
** File description:
** managing valid and correct input for the game.
*/

#include "navy.h"

bool check_wrong_input_pattern(int *input)
{
    if (input[0] < 0 || input[0] > 7 || input[1] < 0 || input[1] > 7) {
        my_putstr("wrong position\n");
        return true;
    }
    return false;
}

boat_t fill_bool_tab(boat_t boat)
{
    for (int i = 0; boat.size > i; i++)
        if (boat.is_hit[i] == false) {
            boat.is_hit[i] = true;
            return (boat);
        }
}

int is_played(char **map, UNUSED boat_t *boat, int *input)
{
    char shoot_pos = map[input[1]][input[0]];

    if (shoot_pos == 'o' || shoot_pos == 'x') {
        my_putstr("wrong position\n");
        return (-1);
    }
    return (0);
}

int check_wrong_input(maps_t *map, boat_t *boat, int *input)
{
    if (check_wrong_input_pattern(input) || is_played(map->nme_map, boat,
    input) == -1)
        return (-1);
    return (0);
}
