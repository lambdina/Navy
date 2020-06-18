/*
** EPITECH PROJECT, 2020
** handshake.c
** File description:
** handles initial handshake between two functions
*/

#include "navy.h"

pid_t connect(void)
{
    pid_t result;
    struct sigaction sa;
    pid_t my_pid = getpid();

    sa.sa_handler = NULL;
    sa.sa_sigaction = get_pid_from_sig;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    mvprintw(LINES / 2, (COLS / 2) - 33, "my_pid: ");
    my_put_nbr((int)my_pid);
    mvprintw((LINES / 2) + 1, (COLS / 2) - 33, "waiting for ennemy connection...");
    print();
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        mvprintw((LINES / 2) + 2, (COLS / 2) - 33, "error getting ennemy's pid");
        print();
        return (-1);
    }
    pause();
    result = (pid_t)g_message;
    mvprintw((LINES / 2) + 2, (COLS / 2) - 33, "ennemy connected");
    print();
    return (result);
}

void get_pid_from_sig(UNUSED int sig, siginfo_t *set, UNUSED void *p)
{
    g_message = 0;
    g_message = (int)set->si_pid;
}

void init_connection(pid_t target_pid)
{
    pid_t my_pid = getpid();

    mvprintw((LINES / 2), (COLS / 2) - 22, "my_pid: ");
    print();
    my_put_nbr((int)my_pid);
    kill(target_pid, SIGUSR1);
    mvprintw((LINES / 2) + 2, (COLS / 2) - 22, "successfully connected");
    print();
}
