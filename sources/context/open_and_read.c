/*
** EPITECH PROJECT, 2019
** open_and_read
** File description:
** open a file, read it, and stores it.
*/

#include "navy.h"

int open_and_read(char *filepath, char **buff, int size)
{
    int fd = 0;
    int return_value = 0;

    if (buff == NULL)
        return (84);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    return_value = read(fd, *buff, size);
    if (return_value == -1)
        return (84);
    close(fd);
    return (0);
}
