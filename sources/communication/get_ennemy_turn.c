/*
** EPITECH PROJECT, 2020
** get_ennemy_turn.c
** File description:
** handles game loop
*/

#include "navy.h"

maps_t get_play(boat_t *boats, maps_t maps, pid_t target_pid)
{
    int *attack_xy = NULL;

    attack_xy = get_input_from_sig(target_pid);
    maps.player_map = check_if_hit(maps.player_map, attack_xy, target_pid);
    free(attack_xy);
    return (maps);
}

static void display_play(int *play)
{
    mvaddch(30, (COLS / 2) - 15, play[1] + 65);
    mvaddch(30, (COLS / 2) - 14, play[0] + 49);
    mvaddch(30, (COLS / 2) - 13, ":");
}

char **check_if_hit(char **map, int *pos_xy, pid_t target)
{
    bool hit = false;

    if (test_if_num(map[pos_xy[0]][pos_xy[1]]))
        hit = true;
    map[pos_xy[0]][pos_xy[1]] = hit == true ? 'x' : 'o';
    display_play(pos_xy);
    if (hit == true) {
        mvprintw(30, (COLS / 2) - 11, " hit");
        kill(target, SIGUSR1);
    } else {
        mvprintw(30, (COLS / 2) - 11, " missed");
        kill(target, SIGUSR2);
    }
    return (map);
}

int *display_turn(int coord, int *res)
{
    int x = coord / 10;
    int y = coord % 10;

    res[0] = y;
    res[1] = x;
    return (res);
}

int *get_input_from_sig(pid_t target_pid)
{
    int *result = malloc(sizeof(int) * 2);
    char *msg_received = NULL;
    int coordinates = 0;

    mvprintw(30, (COLS / 2) - 15, "waiting for ennemy's attack...");
    msg_received = receive_msg(target_pid);
    coordinates = translate_msg_from_binary(msg_received);
    result = display_turn(coordinates, result);
    free(msg_received);
    return (result);
}
