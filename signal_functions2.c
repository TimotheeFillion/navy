/*
** EPITECH PROJECT, 2019
** signal_functions2
** File description:
** contains handlers
*/

#include "my.h"

void handler_usr2_2(int k)
{
    global = 1;
    return;
}

void handler_usr1_2(int k)
{
    global = 0;
    return;
}

char *get_pos_attack(void)
{
    char *pos_attack;

    my_putstr("attack: ");
    pos_attack = get_next_line(0);
    if (pos_attack == NULL)
        return (NULL);
    if (check_pos_attack(pos_attack) == 1)
        return (get_pos_attack());
    return (pos_attack);
}

int check_pos_attack(char *pos_attack)
{
    if (pos_attack[2] != '\0') {
        my_putstr("wrong position\n");
        return (1);
    }
    if (pos_attack[0] < 65 || pos_attack[0] > 72) {
        my_putstr("wrong position\n");
        return (1);
    }
    if (pos_attack[1] < 49 || pos_attack[1] > 56) {
        my_putstr("wrong position\n");
        return (1);
    }
    return (0);
}