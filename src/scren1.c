/*
** EPITECH PROJECT, 2018
** screen1
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <math.h>
#include "window.h"

void    put_vinyl(my_framebuff_t *buff)
{
    sfVector2u  pos = {LM / 2, HM / 2};
    sfVector2i  pos2 = {LM / 2, HM / 2};
    int         tab1[] = {70, 400};
    int         tab2[] = {70, 25, 0, 2, 0, 2};

    draw_vinyl(buff, pos, tab1, sfBlack);
    draw_circle(buff, pos2, tab2, sfRed);
}

int     vinyl(int *nb_scren, my_window_t *win)
{
    float       degre = 0;
    int         tmp_scren = *nb_scren;
    sfVector2u  pos = {LM / 2, HM / 2};
    sfVector2f  pos2 = {LM / 2 - 400, HM / 2 - 500};
    sfVector2i  size = {5, 400};

    while (sfRenderWindow_isOpen(win->window) && *nb_scren == tmp_scren) {
        put_vinyl(win->buff);
        win->buff = rotate(win->buff, degre * M_PI / 180, pos, 400);
        degre = (degre >= 90) ? 0 : degre + 1;
        win->buff = blurring(win->buff, pos, 400);
        square(win->buff, pos2, size, sfWhite);
        update(win);
        clean(win->buff);
        *nb_scren += check(win);
    }
    clean(win->buff);
    return (*nb_scren);
}
