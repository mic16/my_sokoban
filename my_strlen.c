/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** 
*/

int my_strlen1(char const *str, int *tab1)
{
    int a = tab1[0];
    int i = tab1[0];
    int res = 0;

    for (;str[a] != '\n'; a++);
    for (;str[i] != '\n'; i--);
    res = a - i;
    return (res);
}

int my_strlen(char const *str)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'O')
            a += 1;
    }
    return (a);
}

int my_strlen2(char const *str)
{
    int i = 0;

    for (;str[i] != 'P'; i++);
    return (i);
}

int my_strlen3(char const *str)
{
    int i = 0;
    int a = 0;

    for (;str[i] != '\0'; i++) {
        if (str[i] == '\n')
            a = a + 1;
    }
    return (a);
}