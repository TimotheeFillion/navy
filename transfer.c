/*
** EPITECH PROJECT, 2019
** navy
** File description:
** contains function to transfer datas with signals
*/

#include "my.h"

void send_col(char data, int pid2)
{
    int i = 0;

    while (i + 64 != data) {
        usleep(1000);
        kill(pid2, SIGUSR1);
        i++;
    }
    while (i <= 9) {
        usleep(1000);
        kill(pid2, SIGUSR2);
        i++;
    }
    return;
}

void send_line(char data, int pid2)
{
    int i = 0;

    while (i + 48 != data) {
        usleep(1000);
        kill(pid2, SIGUSR1);
        i++;
    }
    while (i <= 9) {
        usleep(1000);
        kill(pid2, SIGUSR2);
        i++;
    }
    return;
}

int get_data(void)
{
    global = 1;

    signal(SIGUSR1, handler_usr1);
    signal(SIGUSR2, handler_usr2);
    for (int i = 0; i != 9; i++)
        pause();
    usleep(1000);
    return (global);
}