/*
** EPITECH PROJECT, 2018
** scren2
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "window.h"
#include "my.h"

void    update_custom2(my_window_t *win, my_framebuff_t *buff)
{
    sfRenderWindow_clear(win->window, sfBlack);
    sfRenderWindow_drawSprite(win->window, win->sprite, NULL);
    sfTexture_updateFromPixels(win->texture, buff->pixels, LM, HM, 0, 0);
    sfTexture_updateFromPixels(win->texture, buff->pixels, LM, HM, 0, 0);
    sfRenderWindow_display(win->window);
}

void    draw_3d(my_window_t *win, sfVector3f *pos, sfColor color)
{
    int tab[] = {10, 0, 0, 2, 0, 2};
    int i = 0;
    sfVector2i  tmp = {0, 0};

    while (i < 8) {
        tmp.x = (LM / 2) + (pos[i].x * 400) / (pos[i].z + 2.5);
        tmp.y = (HM / 2) + (pos[i].y * 400) / (pos[i].z + 2.5);
        tab[0] = 5 * ((-pos[i].z + 2.5));
        draw_circle(win->buff, tmp, tab, color);
        i++;
    }
}

void    rot(sfVector3f *pos, float *angl)
{
    int i = 0;

    while (i < 8) {
        pos[i].x = (cos(angl[0]) * pos[i].x) - (sin(angl[0]) * pos[i].y);
        pos[i].y = (sin(angl[0]) * pos[i].x) + (cos(angl[0]) * pos[i].y);
        pos[i].x = (cos(angl[1]) * pos[i].x) + (sin(angl[1]) * pos[i].z);
        pos[i].z = -(sin(angl[1]) * pos[i].x) + (cos(angl[1]) * pos[i].z);
        pos[i].y = (cos(angl[2]) * pos[i].y) - (sin(angl[2]) * pos[i].z);
        pos[i].z = (sin(angl[2]) * pos[i].y) + (cos(angl[2]) * pos[i].z);
        i++;
    }
}

void    reset_cube(sfVector3f *pos)
{
    sfVector3f  tmp[] = {{-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
{-1, -1, 1}, {1, -1, 1}, {1, 1, 1}, {-1, 1, 1}};
    int i = 0;

    while (i < 8) {
        pos[i].x = tmp[i].x;
        pos[i].y = tmp[i].y;
        pos[i].z = tmp[i].z;
        i++;
    }
}

int     infinit(int *nb_scren, my_window_t *win)
{
    int         tmp_scren = *nb_scren;
    sfVector3f  pos[] = {{-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
{-1, -1, 1}, {1, -1, 1}, {1, 1, 1}, {-1, 1, 1}};
    float       tab[] = {-2 * M_PI / 180, 1 * M_PI / 180, 1 * M_PI / 180};
    int i = 0;

    while (sfRenderWindow_isOpen(win->window) && *nb_scren == tmp_scren) {
        rot(pos, tab);
        draw_3d(win, pos, sfRed);
        update(win);
        clean(win->buff);
        *nb_scren += check(win);
        if (++i >= 4000) {
            reset_cube(pos);
            i = 0;
        }
    }
    update(win);
    return (*nb_scren);
}
