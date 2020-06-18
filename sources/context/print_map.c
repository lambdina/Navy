/*
** EPITECH PROJECT, 2020
** print_map.c
** File description:
** displays map
*/

#include "navy.h"

void display_maps(maps_t map)
{
    char letter = '1';

    mvprintw(5, (COLS / 2) - 15, "my_positions:");
    display_map(map.player_map, letter, 6);
    mvprintw(20, (COLS / 2) - 15, "ennemy's positions:");
    display_map(map.nme_map, letter, 21);
}

char *space(char *str)
{
    int len = my_strlen(str) * 2;
    char *dest = malloc(sizeof(char) * len + 1);
    int i = 0;

    for (int j = 0; i < len; i += 2, j++) {
        dest[i] = str[j];
        dest[i + 1] = ' ';
    }
    dest[i - 1] = 0;
    return (dest);
}

void display_map(char **map, char number, int line)
{
    mvprintw(line, (COLS / 2) - 15, " |A B C D E F G H");
    mvprintw(line + 1, (COLS / 2) - 15, "-+---------------");
    for (int i = 0; map[i] != NULL; i++, number++) {
        mvaddch(line + 2 + i, (COLS / 2) - 15, number);
        mvaddch(line + 2 + i, (COLS / 2) - 15, '|');
        mvprintw(line + 2 + i, (COLS / 2) - 15, space(map[i]));
    }
}
