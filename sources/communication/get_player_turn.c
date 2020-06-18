/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** get_player_turn
*/

#include "navy.h"

maps_t play_new_turn(boat_t *boats, maps_t maps, pid_t target_pid)
{
    char *input = NULL;
    int *attack_xy;
    int message = 0;
    bool hit = false;

    do attack_xy = get_attack_from_user(boats, &maps);
    while (check_wrong_input(&maps, boats, attack_xy));
    message = attack_xy[0] * 10 + attack_xy[1];
    mvaddch(30, (COLS / 2) - 15, attack_xy[0] + 65);
    mvaddch(30, (COLS / 2) - 14, attack_xy[1] + 49);
    mvaddch(30, (COLS / 2) - 13, ':');
    send_msg(message, target_pid);
    hit = receive_is_hit(target_pid);
    mvprintw(30, (COLS / 2) - 11, hit == true ? " hit" : " missed");
    maps.nme_map = apply_to_map(hit, maps.nme_map, attack_xy);
    display_maps(maps);
    print();
    free(attack_xy);
    free(input);
    return (maps);
}

char **apply_to_map(bool is_hit, char **map, int *pos_xy)
{
    char c = is_hit == true ? 'x' : 'o';

    map[pos_xy[1]][pos_xy[0]] = c;
    return (map);
}

bool receive_is_hit(pid_t target_pid)
{
    struct sigaction sa;

    sa.sa_sigaction = &get_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    pause();
    return (g_message == 1 ? true : false);
}

int *get_attack_from_user(boat_t *boats, maps_t *maps)
{
    char *read_result = NULL;
    int *result;

    display_maps(*maps);
    mvprintw(30, (COLS / 2) - 15, "attack: ");
    print();
    read_result = get_next_line(0);
    result = malloc(sizeof(int) * 2);
    result[0] = read_result[0] - 65;
    result[1] = read_result[1] - 49;
    free(read_result);
    return (result);
}
