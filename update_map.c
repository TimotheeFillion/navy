/*
** EPITECH PROJECT, 2019
** navy
** File description:
** contains functions for updating the map
*/

#include "my.h"

void update_map_victim(int line, int col, char **map, int pid)
{
    int i = 0;

    my_putchar(col + 63);
    my_putchar(line + 47);
    usleep(1000);
    if (map[line][col] != '.') {
        my_putstr(": hit\n\n");
        map[line][col] = 'x';
        kill(pid, SIGUSR1);
    } else {
        my_putstr(": missed\n\n");
        map[line][col] = 'o';
        kill(pid, SIGUSR2);
    }
    return;
}

void update_map_attacker(char line, char col, char **map)
{
    int col_nb = col - 63;
    int line_nb = line - 47;

    global = 0;
    my_putchar(col);
    my_putchar(line);
    signal(SIGUSR1,  handler_usr1_2);
    signal(SIGUSR2,  handler_usr2_2);
    pause();
    if (global == 0) {
        my_putstr(": hit\n\n");
        map[line_nb][col_nb] = 'x';
    } else if (global == 1) {
        my_putstr(": missed\n\n");
        map[line_nb][col_nb] = 'o';
    }
    return;
}