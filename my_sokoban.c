/*
** EPITECH PROJECT, 2018
** my_sokoban.c
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

int open_map(char **av);

void check_window(int *tab1)
{
    int row = 0;
    int col = 0;

    getmaxyx(stdscr,row,col);
    while (row < tab1[4] || col < tab1[7]) {
        getmaxyx(stdscr,row,col);
        mvprintw(row / 2, (col - 25) / 2, "%s", "Please resize your window");
        refresh();
        clear();
    }
}

int my_getch(char *buff, int *tab1)
{
    int tab[4] = {0};
    char d = getch();

    tab1[7] = my_strlen1(buff, tab1);
    if (d == ' ')
        return (-1);
    if (d == 'A')
        tab[0] = press_up(buff, tab1);
    if (d == 'D')
        tab[1] = press_left(buff, tab1);
    if (d == 'B')
        tab[2] = press_down(buff, tab1);
    if (d == 'C')
        tab[3] = press_right(buff, tab1);
    if (tab[0] == -2 || tab[1] == -2 || tab[2] == -2 || tab[3] == -2)
        return (-2);
    else
        return (tab1[0]);
}

int open_map(char **av)
{
    int tab1[10] = {0};
    char *buff;

    variables(tab1);
    buff = malloc(sizeof(char) * tab1[6] + 1);
    tab1[5] = open_map_functions(tab1, av, buff);
    var_declaration(tab1, buff);
    close(tab1[5]);
    initscr();
    while (1) {
        check_window(tab1);
        printw("%s", buff);
        tab1[0] = my_getch(buff, tab1);
        if (tab1[0] < 0 || tab1[2] == tab1[8] || tab1[9] > 0) {
            clear_refresh();
            endwin();
            conditions(tab1, av, buff);
        }
        clear_refresh();
    }
    endwin();
}

int main(int ac, char **av)
{
    if (ac != 2) {
        write(1, "LESS_OR_MORE_ARG\n", 17);
        exit(LESS_OR_MORE_ARG);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        write(1, "USAGE\n      ./my_sokoban map\nDESCRIPTION\n     map  ", 52);
        write(1, "file representing the warehouse map, containing '#' fo", 54);
        write(1, "r walls,\n     'P' for the player, 'X' for boxes and ", 52);
        write(1, "'O' for storage locations.\n", 27);
    } else if (open(av[1], O_RDONLY) == -1) {
        write(1, "INVALID_MAP\n", 12);
        exit(INVALID_MAP);
        close(*av[1]);
    } else
        open_map(av);
}