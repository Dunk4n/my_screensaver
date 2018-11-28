/*
** EPITECH PROJECT, 2018
** window
** File description:
** window
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <math.h>
#include "window.h"

void    clean(my_framebuff_t *buff)
{
    int i = 0;

    while (i < LM * HM * 4) {
        buff->pixels[i] = 0;
        i++;
    }
}

void    update(my_window_t *win)
{
    sfRenderWindow_clear(win->window, sfWhite);
    sfRenderWindow_drawSprite(win->window, win->sprite, NULL);
    sfTexture_updateFromPixels(win->texture, win->buff->pixels,
LM, HM, 0, 0);
    sfRenderWindow_display(win->window);
}

int             window(int cnt)
{
    int (*fonc[])(int *nb_scren, my_window_t *win) = {&vinyl, &jeux_olym};
    my_window_t    *win = setwindow();

    while (sfRenderWindow_isOpen(win->window) && cnt >= 0 && cnt <= 1) {
        fonc[cnt](&cnt, win);
        cnt = (cnt < 0) ? 1 : cnt;
        cnt = (cnt > 1) ? 0 : cnt;
    }
    sfClock_destroy(win->clock);
    delete_framebuff(win->buff);
    sfTexture_destroy(win->texture);
    sfSprite_destroy(win->sprite);
    sfRenderWindow_destroy(win->window);
    free(win);
    return (0);
}
