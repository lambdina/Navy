/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** function that split a number into a string.
*/

#include "my.h"

int my_pow(int nb, int pow)
{
    int num = nb;

    if (pow == 0)
        return (1);
    else if (pow == 1)
        return (nb);
    for (; pow > 1; pow--)
        nb = nb * num;
    return (nb);
}

int translate_msg_from_binary(char *message)
{
    int len_message = my_strlen(message) - 1;
    int decimal_message = 0;

    if (message == NULL)
        return -1;
    for (int pos = 0; message[pos] != '\0'; len_message--, pos++)
        decimal_message += (message[pos] -'0') *
        my_pow(2, len_message);
    return (decimal_message);
}

char *my_get_nbr_base(char *base, int nb)
{
    int base_len = my_strlen(base);
    char *output = my_strdup("00000000");
    int i = my_strlen(output) - 1;
    int pos_in_base = 0;

    if (nb < 0)
        return (NULL);
    for (; i >= 0; i--) {
        pos_in_base = nb % base_len;
        output[i] = base[pos_in_base];
        nb = nb / base_len;
    }
    output[8] = 0;
    return (output);
}
