/*
** EPITECH PROJECT, 2019
** main_error_gestion
** File description:
** main error gestion of maps.
*/

#include "navy.h"

bool main_error_gestion(char *file_path)
{
    int size_malloc = 8 * 4;
    char *map = malloc(sizeof(char) * (size_malloc + 1));

    if (open_and_read(file_path, &map, size_malloc))
        return (false);
    map[31] = 0;
    if (check_map(map))
        return (false);
    if (check_intersections_boat(map))
        return (false);
    return (true);
}
