/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** check
*/

#include "my.h"

int check_before_moov(game_t *game, player_t *player, int x, int y)
{
    if (game->str[player->x][player->y] == '#' ||
    game->str[player->x][player->y] == '\0'){
        return (2);
    }
    if (game->str[player->x][player->y] == 'X' &&
    game->str[player->x + x][player->y + y] == 'X'){
        return (2);
    }
    if (game->str[player->x][player->y] == 'X' &&
    game->str[player->x + x][player->y + y] == '#'){
        return (2);
    }
    if (game->str[player->x][player->y] == 'X'){
        game->str[player->x][player->y] = ' ';
        game->str[player->x + x][player->y + y] = 'X';
    }
    return (0);
}

void check_direction(game_t *game, player_t *player, int *x, int *y)
{

    switch (game->direction) {
    case RIGHT:
        player->y++;
        *y = 1;
        break;
    case LEFT:
        player->y--;
        *y = -1;
        break;
    case UP:
        player->x--;
        *x = -1;
        break;
    case DOWN:
        player->x++;
        *x = 1;
        break;
    default: break;
    }
}

void check_endgame(game_t *game, WINDOW *win)
{
    bool winer = true;
    list_t *tmp = game->base;


    while (game->base){
        if (game->str[game->base->lines][game->base->coles] == 'O')
            winer = false;
        game->base = game->base->next;
    }
    if (winer == true){
        my_free(game);
        usleep(100000);
        delwin(win);
        endwin();
        exit (0);
    }
    game->base = tmp;
}

void check_valid_map(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '#' &&
        str[i] != 'X' && str[i] != 'O' && str[i] != 'P' && str[i] != '\0'){
            exit(84);
        }
    }
}

void check_valid_av(char **av)
{
    for (int i = 1; av[i]; i++)
        if (my_strcmp(av[i], "-h") == 0){
            write(1, "USAGE\n", 7);
            write(1, "     ./my_sokoban map\n", 22);
            write(1, "DESCRIPTION\n", 13);
            write(1, "     map file representing the warehouse map,", 46);
            write(1, " containing ‘#’ for walls,\n", 32);
            write(1, "         ‘P’ for the player, ‘X’ for boxes", 51);
            write(1, " and ‘O’ for storage locations.\n", 37);
            exit (0);
        }
}
