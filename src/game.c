/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** game
*/

#include "my.h"

void my_free(game_t *game)
{
    while (game->base){
        list_t *tmp = game->base->next;
        free(game->base);
        game->base = tmp;
    }
    free(game->str);
    free(game->strcp);
    free(game);
}

void my_moove(game_t *game)
{
    player_t *player = malloc(sizeof(player_t));
    int x = 0;
    int y = 0;
    int move = 0;

    player->x = game->player.x;
    player->y = game->player.y;
    check_direction(game, player, &x, &y);
    move = check_before_moov(game, player, x, y);
    if (move < 2){
        game->player.x = player->x;
        game->player.y = player->y;
    }
    free (player);
}

void get_imputs(WINDOW *win, game_t *game)
{
    game->ch = wgetch(win);

    switch (game->ch) {
        case KEY_RIGHT: game->direction = RIGHT;
            my_moove(game); break;
        case KEY_LEFT: game->direction = LEFT;
            my_moove(game); break;
        case KEY_DOWN: game->direction = DOWN;
            my_moove(game); break;
        case KEY_UP: game->direction = UP;
            my_moove(game); break;
        case ' ': reset_map(game); break;
        default: break;
    }
    game->direction = NONE;
}

void check_base(game_t *game)
{
    list_t *tmp = game->base;
    while (game->base){
        if (game->str[game->base->lines][game->base->coles] == ' ')
            game->str[game->base->lines][game->base->coles] = 'O';
        game->base = game->base->next;
    }
    game->base = tmp;
}

void run(WINDOW *win, game_t *game)
{
    char *str = "Aggrandit le terminal !!!";
    while (game->ch != 27) {
        get_imputs(win, game);
        check_base(game);
        if (LINES >= game->lines){
            render(win, game);
        } else {
            my_free(game);
            usleep(100000);
            werase(win);
            mvwprintw(win, LINES / 2, (COLS - my_strlen(str)) / 2, "%s", str);
            wrefresh(win);
        }
        check_endgame(game, win);
        check_blocked(game, win);
        usleep(1000);
    }
    return;
}
// update_box();
