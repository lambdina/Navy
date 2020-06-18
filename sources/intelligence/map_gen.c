/*
** EPITECH PROJECT, 2020
** map_gen.c
** File description:
** map generator for AI
*/


#include "intelligence.h"

maps_t init_ai(boat_t *boats, bool my_turn)
{
    maps_t result;

    result.player_map = gen_map(boats);
    result.nme_map = gen_ai_map();
    result.player_turn = my_turn;
    return (result);
}

char **gen_ai_map(void)
{
    char **result = malloc(sizeof(char *) * 9);

    result[0] = my_strdup("......22");
    result[1] = my_strdup("........");
    result[2] = my_strdup("4444...5");
    result[3] = my_strdup(".......5");
    result[4] = my_strdup(".......5");
    result[5] = my_strdup(".......5");
    result[6] = my_strdup("...333.5");
    result[7] = my_strdup("........");
    result[8] = NULL;
    return (result);
}
