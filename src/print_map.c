/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** print_map
*/

#include "my.h"

void print_map(WINDOW *win, game_t *game, int i, int j)
{
    if (game->str[j][i] == 'P'){
        mvwprintw(win,j, i, " ");
    } else {
        mvwprintw(win,j, i, "%c", game->str[j][i]);
    }
}

void render(WINDOW *win, game_t *game)
{
    werase(win);

    for (int j = 0; game->str[j]; j++){
        for (int i = 0; game->str[j][i]; i++){
            print_map(win, game, i, j);
        }
    }

    mvwprintw(win,game->player.x, game->player.y, "P");
    wrefresh(win);
}
