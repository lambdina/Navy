/*
** EPITECH PROJECT, 2019
** init_window_menu
** File description:
** function that init a menu with ncurses library.
*/

#include "navy.h"

char *choices[] = {
    "Play against AI",
    "Send PID",
    "Receive PID",
};

void print(void)
{
    clear();
    refresh();
}

void free_that_mess(int n_choices, MENU *my_menu, ITEM **my_items)
{
    unpost_menu(my_menu);
    clear();
    refresh();
    for (int i = 0; i < n_choices; i++)
        free_item(my_items[i]);
    free_menu(my_menu);
}

int init_board(void)
{
    int last_choice = 0;
    ITEM **my_items = NULL;
    int c = 0;
    MENU *my_menu = NULL;
    int n_choices = 0;
    ITEM *cur_item = NULL;

    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);

    n_choices = ARRAY_SIZE(choices);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (int i = 0; i < n_choices; ++i) {
        my_items[i] = new_item(choices[i], NULL);
    }
    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    set_menu_fore(my_menu, COLOR_PAIR(1) | A_REVERSE);
    set_menu_back(my_menu, COLOR_PAIR(2));
    set_menu_grey(my_menu, COLOR_PAIR(3));

    mvprintw(LINES - 3, 0, "Press <ENTER> to see the option selected");
    mvprintw(LINES - 2, 0, "Up and Down arrow keys to naviage (ESC to Exit)");
    post_menu(my_menu);
    refresh();

    last_choice = 0;

    while (c != 27) {
        c = getch();
        if (c == KEY_DOWN) {
            last_choice++;
            menu_driver(my_menu, REQ_DOWN_ITEM);
        }
        if (c == KEY_UP) {
            last_choice--;
            menu_driver(my_menu, REQ_UP_ITEM);
        }
        if (c == ENTER) {
            ITEM *cur = current_item(my_menu);
            pos_menu_cursor(my_menu);
            free_that_mess(n_choices, my_menu, my_items);
            return (last_choice);
        }
    }
    free_that_mess(n_choices, my_menu, my_items);
}

int init_display_menu(void)
{
    WINDOW *win = newwin(7, COLS, 20, 0);

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    return (init_board());
}