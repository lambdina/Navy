/*
** EPITECH PROJECT, 2020
** communication.h
** File description:
** communication module header
*/

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "navy.h"

int g_message;

// send_msg.c
void send_msg(int, pid_t);
char *receive_msg(pid_t);
void get_signal(int, siginfo_t *, void *);

// play_game.c
bool play(char *, pid_t, bool, bool);
bool exit_maps(maps_t);
maps_t init_maps(boat_t *, bool);

// handshake.c
pid_t connect(void);
void init_connection(pid_t);
void get_pid_from_sig(int, siginfo_t *, void *);

// get_ennemy_turn.c
maps_t get_play(boat_t *, maps_t, pid_t);
char **check_if_hit(char **, int *, pid_t);
int *display_turn(int, int *);
int *get_input_from_sig(pid_t);

// get_player_turn.c
maps_t play_new_turn(boat_t *, maps_t, pid_t);
int *get_attack_from_user(boat_t *, maps_t *);
bool receive_is_hit(pid_t);
char **apply_to_map(bool, char **, int *);

#endif /* COMMUNICATION_H */
