/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** structures header
*/

#ifndef STRUCT_H
#define STRUCT_H

#include "navy.h"

typedef struct boat_s
{
    int size;
    int *start_xy;
    int *end_xy;
    bool horizontal;
    bool *is_hit;
} boat_t;


typedef struct map_s
{
    char **player_map;
    char **nme_map;
    bool player_turn;
} maps_t;

#endif /* STRUCT_H */
