/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** 
*/

#define LESS_OR_MORE_ARG 84
#define INVALID_MAP 84

int press_up1(char *buff, int *tab1);
int press_up2(char *buff, int *tab1);
int press_up3(char *buff, int *tab1);
int press_up4(char *buff, int *tab1);
int press_up(char *buff, int *tab1);

int press_left1(char *buff, int *tab1);
int press_left2(char *buff, int *tab1);
int press_left3(char *buff, int *tab1);
int press_left4(char *buff, int *tab1);
int press_left(char *buff, int *tab1);

int press_down1(char *buff, int *tab1);
int press_down2(char *buff, int *tab1);
int press_down3(char *buff, int *tab1);
int press_down4(char *buff, int *tab1);
int press_down(char *buff, int *tab1);

int press_right1(char *buff, int *tab1);
int press_right2(char *buff, int *tab1);
int press_right3(char *buff, int *tab1);
int press_right4(char *buff, int *tab1);
int press_right(char *buff, int *tab1);

int my_strlen(char const *str);
int my_strlen1(char const *str, int *tab1);
int my_strlen2(char const *str);
int my_strlen3(char const *str);

void conditions(int *tab1, char **av, char *buff);
int open_map_functions(int *tab1, char **av, char *buff);
void var_declaration(int *tab1, char *buff);
void variables(int *tab1);
void clear_refresh(void);
int open_map(char **av);
void check_exit(int *tab);
void check_lose(char *buff, int *tab1);