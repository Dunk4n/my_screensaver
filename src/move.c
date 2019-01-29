/*
** EPITECH PROJECT, 2018
** src/move
** File description:
** try not to segfault, good luck :)
*/

#include <math.h>
#include "window.h"
#include "my.h"

void            rotate_afect(my_framebuff_t *buff, my_framebuff_t *replace,
float *tab)
{
    sfColor     col = {0, 0, 0, 0};
    long double x = buff->width;
    long double y = buff->height;
    long double costab = cosl(tab[2]);
    long double sintab = sinl(tab[2]);

    col.r = buff->pixels[(int)(buff->width * tab[0] + tab[1]) * 4];
    col.g = buff->pixels[(int)(buff->width * tab[0] + tab[1]) * 4 + 1];
    col.b = buff->pixels[(int)(buff->width * tab[0] + tab[1]) * 4 + 2];
    col.a = buff->pixels[(int)(buff->width * tab[0] + tab[1]) * 4 + 3];
    if (((costab * (tab[1] - x / 2) - sintab * (tab[0] - y / 2) + x /
2) + 0.5) >= 0 && ((costab * (tab[1] - x / 2) - sintab * (tab[0] - y
/ 2) + x / 2) + 0.5) < x && ((sintab * (tab[1] - x / 2) + costab *
(tab[0] - y / 2) + y / 2) + 0.5) >= 0 && ((sintab * (tab[1] - x / 2) +
costab * (tab[0] - y / 2) + y / 2) + 0.5) < y) {
        put_pixel(replace, (int)(costab * (tab[1] - x / 2) - sintab *
(tab[0] - y / 2) + x / 2), (int)(sintab * (tab[1] - x / 2) +
costab * (tab[0] - y / 2) + y / 2), col);
    }
}

my_framebuff_t  *rotate(my_framebuff_t *buff, float angl, sfVector2u pos, int r)
{
    my_framebuff_t      *replace;
    float               tab[3] = {pos.y - r, pos.x - r, angl};

    if ((replace = my_framebuff_create(buff->width, buff->height)) == NULL)
        return (NULL);
    while (tab[0] < pos.y + r) {
        tab[1] = pos.x - r;
        while (tab[1] < pos.x + r) {
            rotate_afect(buff, replace, tab);
            tab[1]++;
        }
        tab[0]++;
    }
    delete_framebuff(buff);
    return (replace);
}

sfColor         set_color2(my_framebuff_t *buff, int i, int j)
{
    sfColor color = {0, 0, 0, 0};

    color.b = ((buff->pixels[(buff->width * (i - 1) + j - 1) * 4 + 2] +
buff->pixels[(buff->width * (i - 1) + j) * 4 + 2] + buff->pixels[(buff->width
* (i - 1) + j + 1) * 4 + 2] + buff->pixels[(buff->width * i + j - 1) * 4 + 2] +
buff->pixels[(buff->width * i + j) * 4 + 2] + buff->pixels[(buff->width * i + j
+ 1) * 4 + 2] + buff->pixels[(buff->width * (i + 1) + j - 1) * 4 + 2] +
buff->pixels[(buff->width * (i + 1) + j) * 4 + 2] + buff->pixels[(buff->width *
(i + 1) + j + 1) * 4 + 2]) / 9);
    color.a = ((buff->pixels[(buff->width * (i - 1) + j - 1) * 4 + 3] +
buff->pixels[(buff->width * (i - 1) + j) * 4 + 3] + buff->pixels[(buff->width
* (i - 1) + j + 1) * 4 + 3] + buff->pixels[(buff->width * i + j - 1) * 4 + 3] +
buff->pixels[(buff->width * i + j) * 4 + 3] + buff->pixels[(buff->width * i + j
+ 1) * 4 + 3] + buff->pixels[(buff->width * (i + 1) + j - 1) * 4 + 3] +
buff->pixels[(buff->width * (i + 1) + j) * 4 + 3] + buff->pixels[(buff->width *
(i + 1) + j + 1) * 4 + 3]) / 9);
    return (color);
}

sfColor         set_color1(my_framebuff_t *buff, int i, int j)
{
    sfColor color = {0, 0, 0, 0};
    sfColor tmp = {0, 0, 0, 0};

    color.r = ((buff->pixels[(buff->width * (i - 1) + j - 1) * 4] +
buff->pixels[(buff->width * (i - 1) + j) * 4] + buff->pixels[(buff->width
* (i - 1) + j + 1) * 4] + buff->pixels[(buff->width * i + j - 1) * 4] +
buff->pixels[(buff->width * i + j) * 4] + buff->pixels[(buff->width * i + j
+ 1) * 4] + buff->pixels[(buff->width * (i + 1) + j - 1) * 4] +
buff->pixels[(buff->width * (i + 1) + j) * 4] + buff->pixels[(buff->width *
(i + 1) + j + 1) * 4]) / 9);
    color.g = ((buff->pixels[(buff->width * (i - 1) + j - 1) * 4 + 1] +
buff->pixels[(buff->width * (i - 1) + j) * 4 + 1] + buff->pixels[(buff->width
* (i - 1) + j + 1) * 4 + 1] + buff->pixels[(buff->width * i + j - 1) * 4 + 1] +
buff->pixels[(buff->width * i + j) * 4 + 1] + buff->pixels[(buff->width * i + j
+ 1) * 4 + 1] + buff->pixels[(buff->width * (i + 1) + j - 1) * 4 + 1] +
buff->pixels[(buff->width * (i + 1) + j) * 4 + 1] + buff->pixels[(buff->width *
(i + 1) + j + 1) * 4 + 1]) / 9);
    tmp = set_color2(buff, i, j);
    color.b = tmp.b;
    color.a = tmp.a;
    return (color);
}

my_framebuff_t  *blurring(my_framebuff_t *buff, sfVector2u pos, int r)
{
    my_framebuff_t  *rep = my_framebuff_create(buff->width, buff->height);
    int i = pos.y - r;
    int j = pos.x - r;
    sfColor color = {0, 0, 0, 0};

    clean(rep);
    while (i < (int)pos.y + r) {
        j = pos.x - r;
        while (j < (int)pos.x + r) {
            color = set_color1(buff, i, j);
            put_pixel(rep, j, i, color);
            j++;
        }
        i++;
    }
    delete_framebuff(buff);
    return (rep);
}
