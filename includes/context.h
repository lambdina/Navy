/*
** EPITECH PROJECT, 2020
** context.h
** File description:
** header context module
*/

#ifndef CONTEXT_H
#define CONTEXT_H

// context / print_maps.c
void display_map(char **, char, int);
char *space(char *);
void display_maps(maps_t);

// context / check_map.c
int abs(int);
int check_pattern(char *, int);
int check_out_of_range(char *, int);
int check_map(char *);

// context / check_boards_intersections.c
int element_in_tab(int *, int *, int, int);
int *fill_that_tab_with(int, int);
int *fill_current_boat_coordinates(char *, int);
int check_intersections_boat(char *);

// context / main_error_gestion.c
bool main_error_gestion(char *);

// context / open_and_read.c
int open_and_read(char *, char **, int);

// context / get_boat_struct.c
boat_t *get_boats_position(char *);
int *get_position_int(char, char);
void free_boats_struct(boat_t *);
boat_t *get_tab_from_read(char *);

// context / error_messages.c
bool display_custom_usage(int);
bool display_usage(void);

// context / input_players.c
int check_wrong_input(maps_t *, boat_t *, int *);
bool check_wrong_input_pattern(int *);
int is_played(char **, boat_t *, int *);
boat_t fill_bool_tab(boat_t);

// context / check_args.c
bool check_args(int, char **);

// context / map_generator.c
int find_incrementation(int *, int *, bool);
char **fill_map_with_boats_position(char **, boat_t *, int);
char **apply_position(char **, boat_t *);
char **gen_map(boat_t *);

// context / game_loop.c
maps_t init_maps(boat_t *, bool);
bool game_over(char **, char **);
int get_nb_hits(char **);

#endif /* CONTEXT_H */
