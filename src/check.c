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
        if (win->event.key.code == sfKeyEscape) {
            sfRenderWindow_close(win->window);
            return (0);
        }
        if (win->event.key.code == sfKeyRight &&
sfTime_asMilliseconds(sfClock_getElapsedTime(win->clock)) >= win->time) {
            win->time = sfTime_asMilliseconds(sfClock_getElapsedTime
(win->clock)) + 1000;
            return (1);
        }
        if (win->event.key.code == sfKeyLeft &&
sfTime_asMilliseconds(sfClock_getElapsedTime(win->clock)) >= win->time) {
            win->time = sfTime_asMilliseconds(sfClock_getElapsedTime
(win->clock)) + 1000;
            return (-1);
        }
    }
    return (0);
}
