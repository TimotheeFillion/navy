/*
** EPITECH PROJECT, 2019
** basic_puts
** File description:
** contains putchar, putstr and put_nbr
*/

#include "my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++)
        my_putchar(str[i]);
    return (0);
}

int my_put_nbr(int nb)
{
    long long decimal = 1;

    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        my_put_nbr(147483648);
    } else {
        if (nb < 0) {
            nb *= -1;
            my_putchar('-');
        }
        while (nb / decimal / 10)
            decimal *= 10;
        while (decimal) {
            my_putchar(nb / decimal + 48);
            nb %= decimal;
            decimal /= 10;
        }
    }
    return (0);
}