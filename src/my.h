/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** my
*/

#pragma once

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

typedef enum  direction {UP, DOWN, LEFT, RIGHT, NONE}  direction;

typedef struct list_s{
    int lines;
    int coles;
    struct list_s *next;
}list_t;

typedef struct player_s{
    int x;
    int y;
}player_t;

typedef struct game_s{
    player_t player;
    list_t *base;
    char **str;
    char **strcp;
    int ch;
    int lines;
    direction direction;
}game_t;

list_t *empty_list(void);
char **my_str_to_word_array (char const *str);
list_t *add_node(list_t *L, int lines, int cols, int pos);
void run (WINDOW *win, game_t *game);
int check_before_moov(game_t *game, player_t *player, int x, int y);
void check_direction(game_t *game, player_t *player, int *x, int *y);
void check_endgame(game_t *game, WINDOW *win);
void render(WINDOW *win, game_t *game);
void check_valid_map(char *str);
void check_valid_av(char **av);
int my_strcmp (char const *str1, char const *str2);
void check_blocked(game_t *game, WINDOW *win);
void remp_linked_list(game_t *game, int j, int i);
void reset_map(game_t *game);
int my_strlen (char const *str);
void my_free(game_t *game);
