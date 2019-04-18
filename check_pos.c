/*
** EPITECH PROJECT, 2019
** navy
** File description:
** check the positions file
*/

#include "my.h"

int check_pos(int ac, char **av)
{
    char *buffer = malloc(33 * sizeof(char));

    if (open(av[ac - 1], O_RDONLY) == -1)
        return (84);
    read(open(av[ac - 1], O_RDONLY), buffer, 32);
    for (int i = 0; i != 4; i++)
        if (buffer[i * 8] != i + 50 || buffer[i * 8 + 1] != ':' ||
        buffer[i * 8 + 4] != ':' || buffer[i * 8 + 2] < 64 ||
        buffer[i * 8 + 2] > 71 || buffer[i * 8 + 5] < 66 ||
        buffer[i * 8 + 5] > 72 || buffer[i * 8 + 3] < 49 ||
        buffer[i * 8 + 3] > 55 || buffer[i * 8 + 6] < 50 ||
        buffer[i * 8 + 6] > 56)
            return (84);
    return (0);
}