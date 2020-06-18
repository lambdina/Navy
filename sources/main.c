/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main file
*/

#include "navy.h"

int main(int ac, char **av)
{
    bool win = false;
    int choice = 0;

    if (check_args(ac, av) == true && main_error_gestion(av[ac - 1]) == true) {
        choice = init_display_menu();
        if (choice == 0)
            win = play_ai(av[1]);
        else if (choice == 1)
            win = play(av[1], 0, true, false);
        else win = play(av[2], (pid_t)my_getnbr(av[1]), false, false);
        return (win == true ? 0 : 1);
    }
    return (84);
}
