/*
** EPITECH PROJECT, 2019
** error_message
** File description:
** displays the correct usage.
*/

#include "navy.h"

bool display_custom_usage(int which_one)
{
    if (which_one == 1)
        my_puterror("A problem has occured with the first argument.\n");
    else if (which_one == 2)
        my_puterror("A problem has occured with the second argument.\n");
    else my_puterror("The number of arguments is incorrect.\n");
    my_puterror("\tRetry with -h for more informations.\n");
    return (false);
}

bool display_usage(void)
{
    my_puterror("USAGE\n\t./navy [first_player_pid] navy_positions\n");
    my_puterror("DESCRIPTION\n\tfirst_player_pid:\tonly for the 2nd player");
    my_puterror("\tpid of the first player.\n\tnavy_positions:\t");
    my_puterror("file representing the positions of the shipe.\n");
    return (false);
}
