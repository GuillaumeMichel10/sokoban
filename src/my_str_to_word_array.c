/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** my_str_to_word_array
*/

#include "my.h"

int compteur_of_n(const char *str)
{
    int compteur = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n')
            compteur++;
    }

    return (compteur);
}

char **my_str_to_word_array (char const *str)
{
    char **nw_str;
    int compteur = compteur_of_n(str);
    int i = 0;
    int x = 0;

    nw_str = malloc(sizeof(char *) * (compteur + 1));
    nw_str[compteur] = NULL;
    for (int s = compteur, j = 0; j < s; j++) {
        compteur = 0;
        for (; str[i] != '\n'; i++, compteur++);
        i++;
        nw_str[j] = malloc(sizeof(char) * (compteur + 1));
        for (int u = 0; str[x] != '\n'; x++, u++)
            nw_str[j][u] = str[x];
        x += 1;
        nw_str[j][compteur] = '\0';
    }

    return (nw_str);
}
