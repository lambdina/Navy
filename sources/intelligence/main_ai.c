/*
** EPITECH PROJECT, 2020
** main_ai.c
** File description:
** main file for ai
*/

#include "navy.h"

static int *get_shoot(int *x, int *y)
{
    int *shoot = malloc(sizeof(int) * 2);

    *x += 2;
    if (*x > 7) {
        *x = 0;
        *y += 2;
    }
    if (*y > 7)
        *y = 0;
    shoot[0] = *x;
    shoot[1] = *y;
    return (shoot);
}

static int *follow_through(int *x, int *y)
{
    int *result = malloc(sizeof(int) * 2);

    *x++;
    if (*x > 7)
        *x -= 2;
    result[0] = *x;
    result[1] = *y;
    return (result);
}

maps_t get_ai_play(boat_t *boats, maps_t maps)
{
    static int y = 0;
    static int x = 0;
    static bool hit = false;
    int *shoot = hit == true ? follow_through(&x, &y) : get_shoot(&x, &y);

    my_putchar(shoot[0] + 65);
    my_putchar(shoot[1] + 49);
    my_putchar(':');
    hit = test_if_num(maps.player_map[shoot[0]][shoot[1]]) ? true : false;
    my_putstr(hit == true ? " hit\n\n" : " missed\n\n");
    maps.player_map = apply_to_map(hit, maps.player_map, shoot);
    free(shoot);
    return (maps);
}

static maps_t play_against_ai(boat_t *boats, maps_t maps, char ***ai_map)
{
     char *input = NULL;
    int *attack_xy;
    int message = 0;
    bool hit = false;

    do attack_xy = get_attack_from_user(boats, &maps);
    while (check_wrong_input(&maps, boats, attack_xy));
    mvaddch(30, (COLS / 2) - 15, attack_xy[0] + 65);
    mvaddch(30, (COLS / 2) - 14, attack_xy[1] + 49);
    mvaddch(30, (COLS / 2) - 13, ':');
    hit = test_if_num(*ai_map[attack_xy[0]][attack_xy[1]]) == true ? true : false;
    *ai_map[attack_xy[0]][attack_xy[1]] = hit == true ? 'x' : 'o';
    mvprintw(30, (COLS / 2) - 11, hit == true ? " hit" : " missed");
    maps.nme_map = apply_to_map(hit, maps.nme_map, attack_xy);
    display_maps(maps);
    print();
    free(attack_xy);
    free(input);
    return (maps);
}

bool play_ai(char *map)
{
    boat_t *boats = get_tab_from_read(map);
    maps_t maps = init_maps(boats, true);
    char **ai_map = gen_ai_map();

    echo();
    while (!game_over(maps.player_map, maps.nme_map)) {
        display_maps(maps);
        if (maps.player_turn == true)
            maps = play_against_ai(boats, maps, &ai_map);
        else maps = get_ai_play(boats, maps);
        maps.player_turn = maps.player_turn == true ? false : true;
        print();
    }
    free_tab(ai_map);
    free_boats_struct(boats);
    return (exit_maps(maps));
}