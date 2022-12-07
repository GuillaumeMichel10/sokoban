/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** main
*/

#include "my.h"

void remp_linked_list(game_t *game, int j, int i)
{
    if (game->str[j][i] == 'P'){
        game->player.x = j;
        game->player.y = i;
    }
    if (game->str[j][i] == 'O')
        game->base = add_node(game->base, j, i, 0);
}

void setup_map(char **av, game_t *game)
{
    int fd = open(av[1], O_RDONLY);
    if (fd == -1)
        exit(84);
    struct stat *buf = malloc(sizeof(struct stat));
    stat(av[1], buf);
    char *buffer = malloc(sizeof(char) * buf->st_size + 1);
    int size = read(fd,buffer,buf->st_size);
    game->base = malloc(sizeof(list_t));
    game->base = empty_list();
    buffer[size] = '\0';
    check_valid_map(buffer);
    game->str = my_str_to_word_array(buffer);
    game->strcp = my_str_to_word_array(buffer);
    for (int j = 0; game->str[j]; j++, game->lines += 1)
        for (int i = 0; game->str[j][i]; i++)
            remp_linked_list(game, j, i);
    free (buf);
    free(buffer);
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;

    local_win = newwin(height, width, starty, startx);
    box(local_win, 0, 0);
    wrefresh(local_win);

    return (local_win);
}

int main(int ac, char **av)
{
    WINDOW *win = NULL;
    game_t *game = malloc(sizeof(game_t));

    if (ac == 1 || ac >= 3)
        return (84);
    check_valid_av(av);
    setup_map(av, game);
    initscr();
    cbreak();
    curs_set(false);
    refresh();
    win = create_newwin(LINES, COLS, 0, 0);
    keypad(win, TRUE);
    nodelay(win, true);
    run(win, game);
    delwin(win);
    endwin();
    return (0);
}
// raw(); // noecho();
// leaveok(win, TRUE);
