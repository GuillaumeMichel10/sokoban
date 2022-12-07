/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** list
*/

#include "my.h"

list_t *empty_list(void)
{
    return NULL;
}

list_t *create_node(int cols, int lines)
{
    list_t *node = malloc(sizeof(list_t));
    if (!node)
        return NULL;
    node->coles = cols;
    node->lines = lines;
    node->next = NULL;

    return (node);
}

list_t *add_node(list_t *L, int lines, int cols, int pos)
{
    list_t *node = create_node(cols, lines);
    if (L == NULL)
        return (node);
    if (pos == 0) {
        node->next = L;
        return (node);
    }
    return (NULL);
}

void free_list(list_t *L)
{
    list_t *tmp = NULL;
    while (L){
        tmp = L->next;
        free(L);
        L = tmp;
    }
    return;
}
