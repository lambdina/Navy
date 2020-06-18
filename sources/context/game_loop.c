/*
** EPITECH PROJECT, 2020
** game_loop.c
** File description:
** game loop utilitary functions
*/

#include "navy.h"

bool game_over(char **player_map, char **nme_map)
{
    return ((get_nb_hits(player_map) == 14 ||
    get_nb_hits(nme_map) == 14) ? true : false);
}

int get_nb_hits(char **maps)
{
    int result = 0;

    for (int i = 0; maps[i] != NULL; i++)
        for (int j = 0; maps[i][j] != '\0'; j++)
            result = maps[i][j] == 'x' ? result + 1 : result;
    return result;
}
