/*
** EPITECH PROJECT, 2020
** send_msg.c
** File description:
** sends a message in binary from a terminal to another
*/

#include "navy.h"

void send_msg(int msg, pid_t target_pid)
{
    char *binary = my_get_nbr_base("01", msg);
    struct sigaction sa;

    sa.sa_handler = NULL;
    sa.sa_sigaction = get_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    for (int i = 0; binary[i] != '\0'; i++) {
        if (binary[i] == '0')
            kill(target_pid, SIGUSR1);
        else kill(target_pid, SIGUSR2);
        pause();
    }
    free(binary);
}

char *receive_msg(pid_t target_pid)
{
    struct sigaction sa;
    int i = 0;
    char *result = malloc(sizeof(char) * 8);

    sa.sa_handler = NULL;
    sa.sa_sigaction = get_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    g_message = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    for (; i < 8; i++) {
        pause();
        result[i] = g_message + 47;
        kill(target_pid, SIGUSR1);
    }
    result[i] = '\0';
    return (result);
}

void get_signal(int sig, UNUSED siginfo_t *set, UNUSED void *p)
{
    g_message = 0;
    g_message = sig == SIGUSR1 ? 1 : sig == SIGUSR2 ? 2 : 0;
}
