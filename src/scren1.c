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

void    put_vinyl(my_window_t *win)
{
    sfVector2u  pos = {LM / 2, HM / 2};
    sfVector2i  pos2 = {LM / 2, HM / 2};
    int         tab1[] = {70, 400};
    int         tab2[] = {70, 25, 0, 2, 0, 2};

    draw_vinyl(win->buff, pos, tab1, sfBlack);
    draw_circle(win->buff, pos2, tab2, sfRed);
}

int     vinyl(int *nb_scren, my_window_t *win)
{
    float       degre = 0;
    int         tmp_scren = *nb_scren;

    while (sfRenderWindow_isOpen(win->window) && *nb_scren == tmp_scren) {
        put_vinyl(win);
        win->buff = rotate(win->buff, degre * M_PI / 180);
        degre = (degre >= 90) ? 0 : degre + 2;
        win->buff = blurring(win->buff, 1);
        update(win);
        clean(win->buff);
        *nb_scren += check(win);
    }
    clean(win->buff);
    return (*nb_scren);
}
