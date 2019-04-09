/*
** EPITECH PROJECT, 2018
** press_right.c
** File description:
** 
*/

#include <stdio.h>

int press_right1(char *buff, int *tab1)
{
    if (buff[tab1[0] + 1] == 'X' && buff[tab1[0] + 2] == 'O') {
        tab1[8]++;
        if (tab1[3] == 1) {
            buff[tab1[0]] = 'O';
            tab1[3] = 0;
        } else
            buff[tab1[0]] = ' ';
        tab1[0] = tab1[0] + 1;
        buff[tab1[0]] = 'P';
        buff[tab1[0] + 1] = 'X';
        return (1);
    }
    return (0);
}

int press_right2(char *buff, int *tab1)
{
    if ((buff[tab1[0] + 1] == 'X' && (buff[tab1[0] + 1 * 3] == '#' || \
    buff[tab1[0] + 1 * 3] == 'X') && (buff[tab1[0] + 1 * 2 - tab1[7]]\
    == '#' || buff[tab1[0] + 1 * 2 - tab1[7]] == 'X')) || \
    (buff[tab1[0] + 1] == 'X' && (buff[tab1[0] + 1 * 3] == '#' || \
    buff[tab1[0] + 1 * 3] == 'X') && (buff[tab1[0] + 1 * 2 + \
    tab1[7]] == '#' || buff[tab1[0] + 1 * 2 + tab1[7]] == 'X')))
        tab1[9]++;
    if (buff[tab1[0] + 1] == 'O') {
        if (tab1[3] == 1) {
            buff[tab1[0]] = 'O';
            tab1[3] = 0;
        } else
            buff[tab1[0]] = ' ';
        tab1[0] = tab1[0] + 1;
        buff[tab1[0]] = 'P';
        tab1[3] = 1;
        return (1);
    }
    return (0);
}

int press_right3(char *buff, int *tab1)
{
    if (buff[tab1[0] + 1] == 'X' && buff[tab1[0] + 1 * 2] == 'X') {
        tab1[0] = tab1[0];
        return (1);
    }
    else if (buff[tab1[0] + 1] == 'X') {
        if (tab1[3] == 1) {
            buff[tab1[0]] = 'O';
            tab1[3] = 0;
        } else
            buff[tab1[0]] = ' ';
        tab1[0] = tab1[0] + 1;
        buff[tab1[0]] = 'P';
        buff[tab1[0] + 1] = 'X';
        return (1);
    }
    return (0);
}

int press_right4(char *buff, int *tab1)
{
    if (tab1[3] == 1) {
        buff[tab1[0]] = 'O';
        tab1[3] = 0;
    } else
        buff[tab1[0]] = ' ';
    tab1[0] = tab1[0] + 1;
    buff[tab1[0]] = 'P';
    return (0);
}

int press_right(char *buff, int *tab1)
{
    int p = 0;
    
    if (buff[tab1[0] + 1] == '#' || \
    (buff[tab1[0] + 1] == 'X' && buff[tab1[0] + 2] == '#')) {
        tab1[0] = tab1[0];
        return (0);
    }
    p = press_right1(buff, tab1);
    if (p == 1)
        return (0);
    p = press_right2(buff, tab1);
    if (p == 1)
        return (0);
    else if (p == -2)
        return (-2);
    p = press_right3(buff, tab1);
    if (p == 1)
        return (0);
    p = press_right4(buff, tab1);
    return (0);
}