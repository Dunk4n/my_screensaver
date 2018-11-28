/*
** EPITECH PROJECT, 2018
** src/line
** File description:
** try not to segfault, good luck :)
*/

#include "window.h"

void    draw_line(my_framebuff_t *buff, sfVector2i *pos, sfColor color)
{
    double x = pos[0].x;
    double a = ((pos[0].x - pos[1].x != 0) ?
(double)(pos[0].y - pos[1].y) / (double)(pos[0].x - pos[1].x) : 0);
    double b = pos[0].y - a * pos[0].x;
    double y = a * x + b;
    int    in = 0;

    while (((int)x != pos[1].x || (int)y != pos[1].y) && (in == 0 ||
(x >= 0 && y >= 0 && x < buff->width && y < buff->height))) {
        if (in == 0 && x >= 0 && y >= 0 && x < buff->width && y < buff->height)
            in = 1;
        if (x != (double)pos[1].x)
            x += ((x < (double)pos[1].x) ? 1 : -1);
        if (x == pos[1].x)
            y += ((y < (double)pos[1].y) ? 1 : -1);
        else
            y = a * x + b;
        put_pixel(buff, x, y, color);
    }
}

void  draw_big_line(my_framebuff_t *buff, sfVector2i *pos, int f,
sfColor color)
{
    sfVector2i rec[] = {pos[0], pos[1]};
    int        ix = (pos[0].y > pos[1].y) ? 1 : -1;
    int        iy = (pos[0].x < pos[1].x) ? 1 : -1;

    if (pos[0].x == pos[1].x && pos[0].y == pos[1].y)
        return ;
    while (rec[0].x < pos[0].x + f && rec[0].x > pos[0].x - f &&
rec[0].y > pos[0].y - f && rec[0].y < pos[0].y + f) {
        draw_line(buff, rec, color);
        if (rec[0].y != rec[1].y) {
            rec[0].x += ix;
            rec[1].x += ix;
        }
        if (rec[0].x != rec[1].x) {
            rec[0].y += iy;
            rec[1].y += iy;
        }
    }
}
