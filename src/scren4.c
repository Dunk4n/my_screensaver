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

void    traine(my_framebuff_t *buff)
{
    int i = 0;

    while (i < LM * HM) {
        buff->pixels[i * 4] /= 1.1;
        buff->pixels[i * 4 + 1] /= 1.1;
        buff->pixels[i * 4 + 2] /= 1.1;
        i++;
    }
}

void    seuil(my_framebuff_t *buff)
{
    int i = 0;
    sfColor color = sfTransparent;

    while (i < LM * HM) {
        color = sfTransparent;
        if (buff->pixels[i * 4] > 50)
            color = sfRed;
        if (buff->pixels[i * 4] > 80 && buff->pixels[i * 4] <= 200)
            color = sfBlue;
        if (buff->pixels[i * 4] > 20 && buff->pixels[i * 4] <= 80)
            color = sfGreen;
        buff->pixels[i * 4] = color.r;
        buff->pixels[i * 4 + 1] = color.g;
        buff->pixels[i * 4 + 2] = color.b;
        buff->pixels[i * 4 + 3] = color.a;
        i++;
    }
}

void    update_custom(my_window_t *win)
{
    my_framebuff_t *bufftmp;
    int            i = 0;

    if ((bufftmp = my_framebuff_create(LM, HM)) == NULL)
        return ;
    while (i < LM * HM * 4) {
        bufftmp->pixels[i] = win->buff->pixels[i];
        i++;
    }
    seuil(bufftmp);
    sfRenderWindow_clear(win->window, sfBlack);
    sfRenderWindow_drawSprite(win->window, win->sprite, NULL);
    sfTexture_updateFromPixels(win->texture, bufftmp->pixels,
LM, HM, 0, 0);
    sfRenderWindow_display(win->window);
    delete_framebuff(bufftmp);
}

void    move_update(sfVector2i *pos, sfVector2i *vit)
{
    int i = 0;

    while (i < 4) {
        if (pos[i].x <= LM / 3 || pos[i].x >= LM / 3 * 2)
            vit[i].x *= -1;
        if (pos[i].y <= HM / 3 || pos[i].y >= HM / 3 * 2)
            vit[i].y *= -1;
        pos[i].x += vit[i].x;
        pos[i].y += vit[i].y;
        i++;
    }
}

int     img(int *nb_scren, my_window_t *win)
{
    int         tmp_scren = *nb_scren;
    sfVector2i  pos[] = {{960, 540}, {960, 540}, {960, 540}, {960, 540}};
    sfVector2i  vit[] = {{5, -3}, {-2, 3}, {-1, -5}, {4, 2}};

    while (sfRenderWindow_isOpen(win->window) && *nb_scren == tmp_scren) {
        draw_blob(win->buff, pos[0], 100, sfRed);
        draw_blob(win->buff, pos[1], 100, sfRed);
        draw_blob(win->buff, pos[2], 100, sfRed);
        draw_blob(win->buff, pos[3], 100, sfRed);
        update_custom(win);
        traine(win->buff);
        move_update(pos, vit);
        *nb_scren += check(win);
    }
    clean(win->buff);
    return (*nb_scren);
}
