/*
** EPITECH PROJECT, 2019
** navy
** File description:
** contains declarations
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

int global;

int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_putchar(char c);
int my_putstr(char const *str);
void return_sig(int k);
void sigaction_test(int i, siginfo_t *info, void *v);
int init_p1(char *filepath);
char **map_builder(void);
char **set_ships(char **map, char *filepath);
void print_map(char **map1, char **map2);
char *get_next_line(int fd);
int my_atoi(char *str);
int init_p2(char *filepath, int pid_player1);
int game_loop_p1(char **map_p1, char **map_p2);
void handler_usr1(int k);
void handler_usr2(int k);
int game_loop_p2(char **map_p2, char **map_p1, int pid_player1);
int decimal_to_binary(int nb);
void send_col(char data, int pid2);
void send_line(char data, int pid2);
int get_data(void);
void print_game(char **map);
void update_map_victim(int line, int col, char **map, int pid);
void handler_usr2_2(int k);
void handler_usr1_2(int k);
void update_map_attacker(char line, char col, char **map);
int check_pos_attack(char *pos_attack);
char *get_pos_attack(void);
int check_pos(int ac, char **av);