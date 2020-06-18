/*
** EPITECH PROJECT, 2019
** display
** File description:
** header needed to the bonus's display.
*/

#ifndef DISPLAY_H
#define DISPLAY_H

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4
#define ENTER 10

// init_window_display.c
void print(void);
void free_that_mess(int n_choices, MENU *my_menu, ITEM **my_items);
int init_board(void);
int init_display_menu(void);

#endif