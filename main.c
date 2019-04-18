/*
** EPITECH PROJECT, 2019
** navy
** File description:
** contains main function
*/

#include "my.h"

void draw_instructions(void)
{
    int fd = open("instructions", O_RDONLY);
    char *buffer = malloc(206 * sizeof(char));

    buffer[206] = '\0';
    read(fd, buffer, 205);
    close(fd);
    my_putstr(buffer);
}

int my_atoi(char *str)
{
    int nbr = 0;
    int i = 0;

    while (str[i] != '\0') {
        nbr = nbr * 10 + (str[i] - 48);
        i++;
    }
    return (nbr);
}

int player2(char *pid, char *filepath)
{
    int my_pid = getpid();
    int pid_player1 = my_atoi(pid);

    my_putstr("my_pid: ");
    my_put_nbr(my_pid);
    my_putchar('\n');
    if (kill(pid_player1, SIGUSR2) !=  0) {
        my_putstr("invalid PID\n");
        return (0);
    }
    signal(SIGUSR1, return_sig);
    pause();
    my_putstr("succesfully connected\n");
    return (init_p2(filepath, pid_player1));
}

int player1(char *filepath)
{
    int pid = getpid();
    struct sigaction act;

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = sigaction_test;
    my_putstr("my_pid: ");
    my_put_nbr(pid);
    my_putstr("\nwaiting for ennemy connection...\n\n");
    sigaction(SIGUSR2, &act, NULL);
    pause();
    my_putstr("ennemy connected\n");
    kill(global, SIGUSR1);
    return (init_p1(filepath));
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        draw_instructions();
        return (0);
    }
    if (ac == 1)
        return (84);
    if (ac == 2) {
        if (check_pos(ac, av))
            return (84);
        return(player1(av[1]));
    }
    if (ac == 3) {
        if (check_pos(ac, av))
            return (84);
        return(player2(av[1], av[2]));
    }
    return (0);
}