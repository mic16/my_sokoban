##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

SRC     =       my_sokoban.c press_up.c press_left.c press_down.c press_right.c my_strlen.c additionnal_functions.c check_lose.c

OBJ     =       my_sokoban.o press_up.o press_left.o press_down.o press_right.o my_strlen.o additionnal_functions.o check_lose.o

CFLAGS = -W -Wall -Wextra -g

all: my_sokoban

my_sokoban: $(OBJ)
	gcc -o my_sokoban $(OBJ) -lncurses $(CFLAGS)

clean:
	rm $(OBJ)

fclean:
	rm my_sokoban

re:     clean fclean all
