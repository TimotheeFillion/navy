/*
** EPITECH PROJECT, 2019
** navy
** File description:
** regroup new functions for signals
*/

#include "my.h"

void return_sig(int k)
{
    return;
}

void handler_usr2(int k)
{
    return;
}

void handler_usr1(int k)
{
    global++;
    return;
}

void sigaction_test(int i, siginfo_t *info, void *v)
{
    global = info->si_pid;
    return;
}

void print_game(char **map)
{
    int i = 0;
    int j = 0;

    while (map[i] != NULL) {
        while (map[i][j] != '\0') {
            my_putchar(map[i][j]);
            j++;
            if (i == 1 && j > 1)
                my_putchar('-');
            if (i != 1 && j > 1)
                my_putchar(' ');
        }
        my_putchar('\n');
        j = 0;
        i++;
    }
}