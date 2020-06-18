/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** intelligence
*/

#ifndef INTELLIGENCE_H
#define INTELLIGENCE_H

#include "navy.h"

// main_ai.c
maps_t get_ai_play(boat_t *, maps_t);

// map_gen.c
maps_t init_ai(boat_t *, bool);
char **gen_ai_map(void);
bool play_ai(char *map);

#endif /* INTELLIGENCE_H */
