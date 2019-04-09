/*
** EPITECH PROJECT, 2018
** press_key.c
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

void check_lose(char *buff, int *tab1)
{
    int a = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == 'X' && ((buff[i + 1] == '#' && buff[i + tab1[7]] == '#')\
        || (buff[i - 1] == '#' && buff[i + tab1[7]] == '#') || (buff[i + 1] ==\
        '#' && buff[i - tab1[7]] == '#') || (buff[i - 1] == '#' && buff[i - \
        tab1[7]] == '#')))
            a++;
        if (a == tab1[2])
            exit(1);
    }
}