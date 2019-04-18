/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** return a line from a fd passed as argument
*/

#include "my.h"

int my_strlen(char const *str)
{
    int n = 0;

    while (str[n] != '\0')
        n++;
    return (n);
}

char *my_realloc(char *str, int size)
{
    char *str2;
    int	i = 0;

    str2 = malloc((my_strlen(str) + size + 1) * sizeof(char));
    while (str[i] != '\0') {
        str2[i] = str[i];
        i++;
    }
    str2[i + 1] = '\0';
    free(str);
    return (str2);
}

char *get_next_line(int fd)
{
    static int line_count = 0;
    char *line = malloc(1 * sizeof(char));
    char *buffer = malloc(1 * sizeof(char));
    int i = 0;
    int rd;

    for (int n = line_count; n > 0; n--) {
        while (buffer[0] != '\n')
            read(fd, buffer, 1);
    }
    line[i] = '\0';
    while (buffer[0] != '\n') {
        rd = read(fd, buffer, 1);
        if (rd == -1 || rd == 0)
            return (NULL);
        line = my_realloc(line, i + 2);
        line[i] = buffer[0];
        i++;
    }
    line[i - 1] = '\0';
    return (line);
}