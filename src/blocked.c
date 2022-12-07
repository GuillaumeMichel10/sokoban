/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** blocked
*/

#include "my.h"

void count_box(int *nb_box, game_t *game, int j, int i)
{
    if (game->str[j][i] == 'X')
        *nb_box += 1;
}

void count_box_c(int *nb_box_c, game_t *game, int j, int i)
{
    if ((game->str[j][i] == 'X' && game->str[j + 1][i] == '#' &&
    game->str[j][i + 1] == '#')
    || (game->str[j][i] == 'X' && game->str[j + 1][i] == '#' &&
    game->str[j][i - 1] == '#')
    || (game->str[j][i] == 'X' && game->str[j - 1][i] == '#' &&
    game->str[j][i + 1] == '#')
    || (game->str[j][i] == 'X' && game->str[j - 1][i] == '#' &&
    game->str[j][i - 1] == '#')){
        *nb_box_c += 1;
    }
}

void check_blocked(game_t *game, WINDOW *win)
{
    int nb_box = 0;
    int nb_box_c = 0;
    for (int j = 0; game->str[j]; j++){
        for (int i = 0; game->str[j][i]; i++){
            count_box(&nb_box, game, j, i);
        }
    }
    for (int j = 0; game->str[j]; j++){
        for (int i = 0; game->str[j][i]; i++){
            count_box_c(&nb_box_c, game, j, i);
        }
    }
    if (nb_box == nb_box_c){
        my_free(game);
        delwin(win);
        endwin();
        exit(1);
    }
}

void reset_map(game_t *game)
{
    for (int j = 0; game->str[j]; j++){
        for (int i = 0; game->str[j][i]; i++){
            game->str[j][i] = game->strcp[j][i];
        }
    }
    for (int j = 0; game->str[j]; j++){
        for (int i = 0; game->str[j][i]; i++){
            remp_linked_list(game, j, i);
        }
    }
}
