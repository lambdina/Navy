/*
** EPITECH PROJECT, 2020
** play_game.c
** File description:
** handles game loop
*/

#include "navy.h"

bool play(char *map, pid_t target_pid, bool my_turn, bool is_ai_on)
{
    boat_t *boats = get_tab_from_read(map);
    maps_t maps = !is_ai_on ? init_maps(boats, my_turn) : init_ai(boats, true);

    if (target_pid == 0)
        target_pid = connect();
    else init_connection(target_pid);
    echo();
    while (!game_over(maps.player_map, maps.nme_map)) {
        display_maps(maps);
        if (maps.player_turn == true)
            maps = play_new_turn(boats, maps, target_pid);
        else maps = is_ai_on == false ? get_play(boats, maps, target_pid) :
        get_ai_play(boats, maps);
        maps.player_turn = maps.player_turn == true ? false : true;
        print();
    }
    free_boats_struct(boats);
    return (exit_maps(maps));
}

bool exit_maps(maps_t maps)
{
    if (maps.player_turn == true) {
        mvprintw(LINES - 1, (COLS / 2) - 15, "Ennemy won");
        return false;
    } else mvprintw(LINES - 1, (COLS / 2) - 15, "I won");
    display_maps(maps);
    free_tab(maps.player_map);
    free_tab(maps.nme_map);
    return true;
}

maps_t init_maps(boat_t *boats, bool is_player_turn)
{
    maps_t result;

    result.player_map = gen_map(boats);
    result.nme_map = gen_map(NULL);
    result.player_turn = is_player_turn;
    return (result);
}
