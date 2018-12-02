/*
** EPITECH PROJECT, 2018
** scren3
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "window.h"

int     tree(my_window_t *win, sfVector2i *npos, int nb, int size)
{
    sfVector2i  pos[] = {{npos[1].x, npos[1].y}, {npos[1].x, npos[1].y}};
    sfColor     colorB = {150, 75, 0, 255};
    sfColor     colorG = {74, 120 + (rand() % 10 - 5), 32, 255};
    int         tab[] = {100, 0, 0, 2, 0, 2};

    if (nb <= 0) {
        draw_circle(win->buff, npos[0], tab, colorG);
        return (0);
    }
    draw_line(win->buff, npos, size, colorB);
    update(win);
    pos[1].x = pos[1].x - (rand() % 300 - 50);
    pos[1].y = npos[1].y - ((npos[0].y - npos[1].y) / 2) - (rand() % 150 - 35);
    if (tree(win, pos, nb - 1, size / 1.2) == 1)
        return (1);
    pos[1].x = pos[0].x + (rand() % 300 - 50);
    if (tree(win, pos, nb - 1, size / 1.2) == 1)
        return (1);
    return (0);
}

int     binary(int *nb_scren, my_window_t *win)
{
    int         tmp_scren = *nb_scren;
    sfVector2i  pos[] = {{960, 1080}, {960, 900}};

    srand(time(NULL));
    while (sfRenderWindow_isOpen(win->window) && *nb_scren == tmp_scren) {
        tree(win, pos, 6, 25);
        update(win);
        clean(win->buff);
        *nb_scren += check(win);
    }
    update(win);
    return (*nb_scren);
}
