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
    int         x = buff->width;
    int         y = buff->height;

    col.r = buff->pixels[(int)(buff->width * tab[0] + tab[1]) * 4];
    col.g = buff->pixels[(int)(buff->width * tab[0] + tab[1]) * 4 + 1];
    col.b = buff->pixels[(int)(buff->width * tab[0] + tab[1]) * 4 + 2];
    col.a = buff->pixels[(int)(buff->width * tab[0] + tab[1]) * 4 + 3];
    if (((cos(tab[2]) * (tab[1] - x / 2) - sin(tab[2]) * (tab[0] - y / 2) + x /
2) + 0.5) >= 0 && ((cos(tab[2]) * (tab[1] - x / 2) - sin(tab[2]) * (tab[0] - y
/ 2) + x / 2) + 0.5) < x && ((sin(tab[2]) * (tab[1] - x / 2) + cos(tab[2]) *
(tab[0] - y / 2) + y / 2) + 0.5) >= 0 && ((sin(tab[2]) * (tab[1] - x / 2) +
cos(tab[2]) * (tab[0] - y / 2) + y / 2) + 0.5) < y) {
        put_pixel(replace, (int)((cos(tab[2]) * (tab[1] - x / 2) - sin(tab[2]) *
(tab[0] - y / 2) + x / 2) + 0.5), (int)((sin(tab[2]) * (tab[1] - x / 2) +
cos(tab[2]) * (tab[0] - y / 2) + y / 2) + 0.5), col);
    }
}

my_framebuff_t  *rotate(my_framebuff_t *buff, float angl)
{
    my_framebuff_t      *replace;
    float               tab[3] = {0, 0, angl};

    if ((replace = my_framebuff_create(buff->width, buff->height)) == NULL)
        return (NULL);
    while (tab[0] < buff->height) {
        tab[1] = 0;
        while (tab[1] < buff->width) {
            rotate_afect(buff, replace, tab);
            tab[1]++;
        }
        tab[0]++;
    }
    return (replace);
}

void            blur(my_framebuff_t *buff, int *tab)
{
    if (tab[1] + tab[3] >= 0 && tab[1] + tab[3] < buff->height &&
tab[0] + tab[2] >= 0 && tab[0] + tab[2] < buff->width) {
        tab[4] += buff->pixels[(buff->width * (tab[1] + tab[3]) + (tab[0] +
tab[2])) * 4];
        tab[5] += buff->pixels[(buff->width * (tab[1] + tab[3]) + (tab[0] +
tab[2])) * 4 + 1];
        tab[6] += buff->pixels[(buff->width * (tab[1] + tab[3]) + (tab[0] +
tab[2])) * 4 + 2];
        tab[7] += buff->pixels[(buff->width * (tab[1] + tab[3]) + (tab[0] +
tab[2])) * 4 + 3];
    }
}

void            set_blur(my_framebuff_t *rep, int *tab, int f)
{
    rep->pixels[(rep->width * tab[1] + tab[0]) * 4] = tab[4] /
pow(f * 2 + 1, 2);
    rep->pixels[(rep->width * tab[1] + tab[0]) * 4 + 1] = tab[5] /
pow(f * 2 + 1, 2);
    rep->pixels[(rep->width * tab[1] + tab[0]) * 4 + 2] = tab[6] /
pow(f * 2 + 1, 2);
    rep->pixels[(rep->width * tab[1] + tab[0]) * 4 + 3] = tab[7] /
pow(f * 2 + 1, 2);
    tab[4] = 0;
    tab[5] = 0;
    tab[6] = 0;
    tab[7] = 0;
}

my_framebuff_t  *blurring(my_framebuff_t *buff, int force)
{
    my_framebuff_t      *rep = my_framebuff_create(buff->width, buff->height);
    int                 tab[] = {0, 0, -force, -force, 0, 0, 0, 0};

    while (tab[1] < buff->height) {
        tab[0] = 0;
        while (tab[0] < buff->width) {
            tab[2] = -force;
            while (tab[2] <= force) {
                tab[3] = -force;
                while (tab[3] <= force) {
                    blur(buff, tab);
                    tab[3]++;
                }
                tab[2]++;
            }
            set_blur(rep, tab, force);
            tab[0]++;
        }
        tab[1]++;
    }
    return (rep);
}
