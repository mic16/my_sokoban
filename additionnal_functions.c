/*
** EPITECH PROJECT, 2018
** additionnal_functions.c
** File description:
** 
*/
#include <unistd.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void conditions(int *tab1, char **av, char *buff)
{
    if (tab1[2] == tab1[8])
        exit(0);
    else if (tab1[0] == -1)
        open_map(av);
    else
        check_lose(buff, tab1);
}

int open_map_functions(int *tab1, char **av, char *buff)
{
    tab1[5] = open(av[1], O_RDONLY);
    read(tab1[5], buff, tab1[6]);
    buff[tab1[6]] = '\0';
    return (tab1[5]);
}

void var_declaration(int *tab1, char *buff)
{
    tab1[0] = my_strlen2(buff);
    tab1[2] = my_strlen(buff);
    tab1[4] = my_strlen3(buff) + 1;
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] != ' ' && buff[i] != '#' && buff[i] != 'P' && \
        buff[i] != 'X' && buff[i] != '\n' && buff[i] != 'O') {
            write(1, "INVALID_MAP\n", 12);
            exit(5);
        }
    }
}

void variables(int *tab1)
{
    tab1[0] = 0;
    tab1[1] = 0;
    tab1[2] = 0;
    tab1[3] = 0;
    tab1[4] = 0;
    tab1[5] = 0;
    tab1[6] = 50000;
    tab1[7] = 0;
    tab1[8] = 0;
    tab1[9] = 0;
}

void clear_refresh(void)
{
    refresh();
    clear();
}