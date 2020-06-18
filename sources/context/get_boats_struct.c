/*
** EPITECH PROJECT, 2020
** get_boat_struct.c
** File description:
** handles boats structure // these functions assume that error handling is ok
*/

#include "navy.h"

boat_t *get_boats_position(char *buffer)
{
    boat_t *boats = malloc(sizeof(*boats) * 4);
    char **tab = tabgen(buffer, '\n');

    for (int i = 0; i < 4; i++) {
        boats[i].size = tab[i][0] - 48;
        boats[i].is_hit = malloc(sizeof(bool) * boats[i].size);
        for (int j = 0; j < boats[i].size; j++)
            boats[i].is_hit[j] = false;
        boats[i].start_xy = get_position_int(tab[i][2], tab[i][3]);
        boats[i].end_xy = get_position_int(tab[i][5], tab[i][6]);
        boats[i].horizontal = tab[i][2] == tab[i][5] ? false : true;
    }
    free(buffer);
    free_tab(tab);
    return (boats);
}

int *get_position_int(char first, char second)
{
    int *result = malloc(sizeof(int) * 2);

    result[0] = second - '0' - 1;
    result[1] = first - 'A';
    return (result);
}

void free_boats_struct(boat_t *boats)
{
    for (int i = 0; i < 4; i++) {
        free(boats[i].is_hit);
        free(boats[i].start_xy);
        free(boats[i].end_xy);
    }
    free(boats);
}

boat_t *get_tab_from_read(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 33);
    boat_t *result;
    int size = read(fd, buffer, 32);

    buffer[size] = '\0';
    result = get_boats_position(buffer);
    close(fd);
    return (result);
}
