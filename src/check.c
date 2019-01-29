/*
** EPITECH PROJECT, 2018
** put
** File description:
** put
*/

#include <stdlib.h>
#include "window.h"

int     check(my_window_t *win)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event))) {
        if (win->tmp == 1) {
            win->tmp = 0;
            return (0);
        }
        if (win->event.key.code == sfKeyEscape) {
            sfRenderWindow_close(win->window);
            return (0);
        }
        if (win->event.key.code == sfKeyRight && win->tmp == 0) {
            win->tmp = 1;
            return (1);
        }
        if (win->event.key.code == sfKeyLeft && win->tmp == 0) {
            win->tmp = 1;
            return (-1);
        }
        if (win->event.key.code == sfKeyLAlt || win->event.key.code == sfKeyTab) {
            sfRenderWindow_close(win->window);
            return (0);
        }
    }
    return (0);
}
