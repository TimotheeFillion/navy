/*
** EPITECH PROJECT, 2019
** navy
** File description:
** contains functions for the map
*/

#include "my.h"

char **long_ships(char **map, char *buffer, char ship_size)
{
    int i = 0;
    int ship_lenght = ship_size - 48;

    if (buffer[2] == buffer[5]) {
        while (i < ship_lenght) {
            map[buffer[3] - 47 + i][buffer[2] - 63] = ship_size;
            i++;
        }
    }
    i = 0;
    if (buffer[3] == buffer[6]) {
        while (i < ship_lenght) {
            map[buffer[3] - 47][buffer[2] - 63 + i] = ship_size;
            i++;
        }
    }
    return (map);
}

char **set_ships(char **map, char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = (get_next_line(fd));

    map[buffer[3] - 47][buffer[2] - 63] = '2';
    map[buffer[6] - 47][buffer[5] - 63] = '2';
    map = long_ships(map, get_next_line(fd), '3');
    map = long_ships(map, get_next_line(fd), '4');
    map = long_ships(map, get_next_line(fd), '5');
    return (map);
}

void print_map(char **map1, char **map2)
{
    int i = 0;
    int j = 0;

    my_putstr("my_positions:\n");
    print_game(map1);
    my_putstr("\nennemy's positions:\n");
    print_game(map2);
    my_putchar('\n');
    return;
}

char **fill_map(char **map)
{
    int j = 2;

    map[0][0] = ' ';
    map[0][1] = '|';
    map[1][0] = '-';
    map[1][1] = '+';
    for (int i = 2; i != 10; i++) {
        map[0][i] = i + 63;
        map[i][0] = i + 47;
        map[i][1] = '|';
        map[1][i] = '-';
    }
    while (map[j] != NULL) {
        for (int i = 2; i != 10; i++)
            map[j][i] = '.';
        j++;
    }
    return (map);
}

char **map_builder(void)
{
    char **map = malloc(12 * sizeof(char*));
    int i = 0;

    while (i != 10) {
        map[i] = malloc(10 * sizeof(char));
        map[i][9] = '\0';
        i++;
    }
    map[i] = NULL;
    map = fill_map(map);
    return (map);
}