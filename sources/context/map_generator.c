/*
** EPITECH PROJECT, 2019
** map_generator
** File description:
** generates map
*/

#include "navy.h"

int find_incrementation(int *start_xy, int *end_xy, bool is_horizontal)
{
    int diff = 0;
    int col_or_line = is_horizontal == true ? 1 : 0;

    diff = end_xy[col_or_line] - start_xy[col_or_line];
    return (diff > 0 ? 1 : - 1);
}

char **fill_map_with_boats_position(char **map, boat_t *boats, int b_pos)
{
    int inc = find_incrementation(boats[b_pos].start_xy, boats[b_pos].end_xy,
    boats[b_pos].horizontal);
    int m_pos = boats[b_pos].start_xy[0];
    int col = boats[b_pos].start_xy[1];

    for (int count = 0; count < boats[b_pos].size; count++) {
        map[m_pos][col] = boats[b_pos].size + 48;
        if (boats[b_pos].horizontal == true)
            col += inc;
        else m_pos += inc;
    }
    return (map);
}

char **apply_position(char **map, boat_t *boat)
{
    for (int i = 0; i < 4; i++)
        map = fill_map_with_boats_position(map, boat, i);
    return (map);
}

char **gen_map(boat_t *boats)
{
    char **tab = malloc(sizeof(char *) * 9);

    for (int i = 0; i < 8; i++)
        tab[i] = my_strdup("........");
    tab[8] = NULL;
    return (boats == NULL ? tab : apply_position(tab, boats));
}
