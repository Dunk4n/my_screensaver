/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** my_split_whites_spaces
*/

#include <stdlib.h>

static int     alpha_num(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
(c >= '0' && c <= '9'))
        return (1);
    else
        return (0);
}

static int     charword(char const *str, int n, int nl)
{
    int i = 0;
    int sp = 1;
    int nb = 0;
    int let = 0;

    while (str[i] != '\0') {
        if (sp == 1 && alpha_num(str[i])  == 1) {
            sp = 0;
            nb++;
        }
        sp = (alpha_num(str[i]) == 0) ? 1 : 0;
        let += (alpha_num(str[i]) == 1 && nb == n) ? 1 : 0;
        if (let == nl)
            return (str[i]);
        i++;
    }
    return ('\0');
}

static int     nbchar(char const *str, int n)
{
    int i = 0;
    int sp = 1;
    int nb = 0;
    int let = 0;

    while (str[i] != '\0') {
        if (sp == 1 && alpha_num(str[i])  == 1) {
            sp = 0;
            nb++;
        }
        sp = (alpha_num(str[i]) == 0) ? 1 : 0;
        let += (alpha_num(str[i]) == 1 && nb == n) ? 1 : 0;
        i++;
    }
    return (let);
}

static int     nbword(char const *str)
{
    int i = 0;
    int sp = 1;
    int nb = 0;

    while (str[i] != '\0') {
        if (sp == 1 && alpha_num(str[i])  == 1) {
            sp = 0;
            nb++;
        }
        sp = (alpha_num(str[i]) == 0) ? 1 : 0;
        i++;
    }
    return (nb);
}

char    **my_str_to_word_array(char const *str)
{
    int i = 1;
    int j = 1;
    char **tab = malloc(sizeof(char*) * (nbword(str) + 1));

    while (i - 1 < nbword(str)) {
        tab[i - 1] = malloc(nbchar(str, i));
        j = 1;
        while (j - 1 < nbchar(str, i)) {
            tab[i - 1][j - 1] = charword(str, i, j);
            j++;
        }
        tab[i - 1][j - 1] = '\0';
        i++;
    }
    tab[i - 1] = 0;
    return (tab);
}
