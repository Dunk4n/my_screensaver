/*
** EPITECH PROJECT, 2018
** scren2
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <math.h>
#include "window.h"

void    draw_olym(my_window_t *win, sfVector2i  *pos, int **tab)
{
    clean(win->buff);
    draw_circle(win->buff, pos[0], tab[2], sfBlue);
    draw_circle(win->buff, pos[4], tab[0], sfRed);
    draw_circle(win->buff, pos[3], tab[0], sfGreen);
    draw_circle(win->buff, pos[2], tab[0], sfBlack);
    draw_circle(win->buff, pos[1], tab[1], sfYellow);
    draw_circle(win->buff, pos[0], tab[0], sfBlue);
    draw_circle(win->buff, pos[2], tab[2], sfBlack);
    draw_circle(win->buff, pos[3], tab[2], sfGreen);
    draw_circle(win->buff, pos[4], tab[2], sfRed);
}

void    draw_cadre(my_window_t *win)
{
    sfVector2i  pos1[] = {{300, 250}, {1500, 150}};
    sfVector2i  pos2[] = {{500, 850}, {1700, 750}};
    sfVector2i  pos3[] = {{300, 250}, {500, 850}};
    sfVector2i  pos4[] = {{1500, 150}, {1700, 750}};

    draw_line(win->buff, pos1, 10, sfRed);
    draw_line(win->buff, pos2, 10, sfRed);
    draw_line(win->buff, pos3, 10, sfRed);
    draw_line(win->buff, pos4, 10, sfRed);
}

void    anime(int *tab[6], int *cnt)
{
    int i = 0;

    *cnt = (tab[0][0] <= 120) ? 1 : *cnt;
    *cnt = (tab[0][0] >= 140) ? -1 : *cnt;
    while (i < 3) {
        tab[i][0] += *cnt;
        tab[i][1] -= *cnt;
        i++;
    }
}

void    asign(int **tab)
{
    int i = 0;
    int j = 0;
    int tmp[][6] = {{130, 120, 0, 1, 0, 2}, {130, 120, 0, 2, 0, 2},
{130, 120, 1, 2, 1, 2}};

    while (i < 3) {
        tab[i] = malloc(sizeof(int) * 6);
        j = 0;
        while (j < 6) {
            tab[i][j] = tmp[i][j];
            j++;
        }
        i++;
    }
}

int     jeux_olym(int *nb_scren, my_window_t *win)
{
    int         cnt = 1;
    int         tmp_scren = *nb_scren;
    int         **tab = malloc(sizeof(int*) * 3);
    sfVector2i  pos[] = {{660, 450}, {810, 550}, {960, 450}, {1110, 550},
{1260, 450}};

    asign(tab);
    while (sfRenderWindow_isOpen(win->window) && *nb_scren == tmp_scren) {
        update(win);
        draw_olym(win, pos, tab);
        draw_cadre(win);
        anime(tab, &cnt);
        *nb_scren += check(win);
    }
    free(tab[0]);
    free(tab[1]);
    free(tab[2]);
    free(tab);
    clean(win->buff);
    return (*nb_scren);
}
