/*
** EPITECH PROJECT, 2018
** display
** File description:
** try not to segfault, good luck :)
*/

#include "window.h"

void    put_pixel(my_framebuff_t *framebuff, int x, int y, sfColor color)
{
    if (x > framebuff->width || x < 0 || y > framebuff->height || y < 0)
        return ;
    framebuff->pixels[(framebuff->width * y + x) * 4] = color.r;
    framebuff->pixels[(framebuff->width * y + x) * 4 + 1] = color.g;
    framebuff->pixels[(framebuff->width * y + x) * 4 + 2] = color.b;
    framebuff->pixels[(framebuff->width * y + x) * 4 + 3] = color.a;
}

void    put_add_pixel(my_framebuff_t *framebuff, int x, int y, sfColor color)
{
    int i;
    int j;
    int k;

    if (x > framebuff->width || x < 0 || y > framebuff->height || y < 0)
        return ;
    i = ((double)color.r * ((double)color.a / 255.0)) +
((double)framebuff->pixels[(framebuff->width * y + x) * 4]);
    j = ((double)color.g * ((double)color.a / 255.0)) +
((double)framebuff->pixels[(framebuff->width * y + x) * 4]);
    k = ((double)color.b * ((double)color.a / 255.0)) +
((double)framebuff->pixels[(framebuff->width * y + x) * 4]);
    i = (i > 255) ? 255 : i;
    j = (j > 255) ? 255 : j;
    k = (k > 255) ? 255 : k;
    framebuff->pixels[(framebuff->width * y + x) * 4] = i;
    framebuff->pixels[(framebuff->width * y + x) * 4 + 1] = j;
    framebuff->pixels[(framebuff->width * y + x) * 4 + 2] = k;
    framebuff->pixels[(framebuff->width * y + x) * 4 + 3] = 255;
}

void    draw_square(my_framebuff_t *buff, sfVector2u pos, unsigned int size,
sfColor color)
{
    unsigned int i = 0;
    unsigned int j = 0;

    while (i < size) {
        j = 0;
        while (j < size) {
            put_pixel(buff, pos.x + j, pos.y + i, color);
            j++;
        }
        i++;
    }
}

void    draw_vbord(my_framebuff_t *buff, sfVector2u pos, int r, sfColor color)
{
    int tab[] = {r - 1, 0, 1, 1, 1 - (r << 1)};

    while (tab[0] >= tab[1])
    {
        put_pixel(buff, pos.x + tab[0], pos.y + tab[1], color);
        put_pixel(buff, pos.x + tab[1], pos.y + tab[0], color);
        put_pixel(buff, pos.x - tab[1], pos.y + tab[0], color);
        put_pixel(buff, pos.x - tab[0], pos.y + tab[1], color);
        put_pixel(buff, pos.x - tab[0], pos.y - tab[1], color);
        put_pixel(buff, pos.x - tab[1], pos.y - tab[0], color);
        put_pixel(buff, pos.x + tab[1], pos.y - tab[0], color);
        put_pixel(buff, pos.x + tab[0], pos.y - tab[1], color);
        if (tab[4] <= 0) {
            tab[1]++;
            tab[4] += tab[3];
            tab[3] += 2;
        }
        (tab[4] > 0) ? tab[0]-- : 0;
        tab[2] = (tab[4] > 0) ? tab[2] + 2 : tab[2];
        tab[4] = (tab[4] > 0) ? tab[4] + tab[2] - (r << 1) : tab[4];
    }
}

void    draw_vinyl(my_framebuff_t *buff, sfVector2u pos, int *tab,
sfColor color)
{
    int i = tab[0];
    int j = tab[1];

    while (i < j) {
        draw_vbord(buff, pos, i, color);
        i++;
    }
}
