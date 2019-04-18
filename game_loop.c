/*
** EPITECH PROJECT, 2019
** navy
** File description:
** contains game_loop
*/

#include "my.h"

int count_x(char **map)
{
    int nb_x = 0;
    int i = 0;
    int j = 0;

    while (map[i] != NULL) {
        while (map[i][j] != '\0') {
            if (map[i][j] == 'x')
                nb_x++;
            j++;
        }
        j = 0;
        i++;
    }
    return (nb_x);
}

int init_p1(char *filepath)
{
    char **map_p1 = map_builder();
    char **map_p2 = map_builder();

    map_p1 = set_ships(map_p1, filepath);
    if (game_loop_p1(map_p2, map_p1) == 84)
        return (84);
    print_map(map_p1, map_p2);
    if (count_x(map_p2) == 14) {
        my_putstr("\nI won\n");
        return (0);
    }
    my_putstr("\nEnnemy won\n");
    return (1);
}

int init_p2(char *filepath, int pid_player1)
{
    char **map_p2 = map_builder();
    char **map_p1 = map_builder();

    map_p2 = set_ships(map_p2, filepath);
    if (game_loop_p2(map_p2, map_p1, pid_player1) == 84)
        return (84);
    print_map(map_p1, map_p2);
    if (count_x(map_p1) == 14) {
        my_putstr("\nI won\n");
        return (0);
    }
    my_putstr("\nEnnemy won\n");
    return (1);
}

int game_loop_p1(char **map_p1, char **map_p2)
{
    char *pos_attack;
    int pid2 = global;
    int col = 0;
    int line = 0;

    while (count_x(map_p1) !=  14 && count_x(map_p2) != 14) {
        print_map(map_p1, map_p2);
        pos_attack = get_pos_attack();
        if (pos_attack == NULL)
            return (84);
        send_col(pos_attack[0], pid2);
        send_line(pos_attack[1], pid2);
        update_map_attacker(pos_attack[1], pos_attack[0], map_p2);
        my_putstr("waiting for ennemy's attack...\n");
        col = get_data();
        line = get_data();
        update_map_victim(line, col, map_p1, pid2);
    }
    return (0);
}

int game_loop_p2(char **map_p2, char **map_p1, int pid_player1)
{
    char *pos_attack;
    int col = 0;
    int line = 0;

    while (count_x(map_p1) != 14 || count_x(map_p2) != 14) {
        signal(SIGUSR1, handler_usr1);
        signal(SIGUSR2, handler_usr2);
        print_map(map_p2, map_p1);
        my_putstr("waiting for enemy’s attack...\n");
        col = get_data();
        line = get_data();
        update_map_victim(line, col, map_p2, pid_player1);
        pos_attack = get_pos_attack();
        if (pos_attack == NULL)
            return (84);
        if (check_pos_attack(pos_attack) == 1)
            return (game_loop_p2(map_p2, map_p1, pid_player1));
        send_col(pos_attack[0], pid_player1);
        send_line(pos_attack[1], pid_player1);
        update_map_attacker(pos_attack[1], pos_attack[0], map_p1);
    }
    return (0);
}