/*
** EPITECH PROJECT, 2018
** src/line
** File description:
** try not to segfault, good luck :)
*/

#include "window.h"

void    draw_lineX(my_framebuff_t *buff, sfVector2i *pos, int r, sfColor color)
{
    double a = (double)(pos[0].y - pos[1].y) / (double)(pos[0].x - pos[1].x);
    double b = (double)pos[0].y - a * (double)pos[0].x;
    sfVector2f ptr = {pos[0].x, pos[0].y};
    sfVector2i size = {r, r};

    while ((int)ptr.x != pos[1].x) {
        ptr.x += ((ptr.x < (double)pos[1].x) ? 1.0 : -1.0);
        ptr.y = a * ptr.x + b;
        if (r > 1)
            square(buff, ptr, size, color);
        else
            put_pixel(buff, ptr.x, ptr.y, color);
    }
}

void    draw_lineY(my_framebuff_t *buff, sfVector2i *pos, int r, sfColor color)
{
    double a = (double)(pos[0].x - pos[1].x) / (double)(pos[0].y - pos[1].y);
    double b = (double)pos[0].x - a * (double)pos[0].y;
    sfVector2f ptr = {pos[0].x, pos[0].y};
    sfVector2i size = {r, r};

    while ((int)ptr.y != pos[1].y) {
        ptr.y += ((ptr.y < (double)pos[1].y) ? 1.0 : -1.0);
        ptr.x = a * ptr.y + b;
        if (r > 1)
            square(buff, ptr, size, color);
        else
            put_pixel(buff, ptr.x, ptr.y, color);
    }
}

void    draw_line(my_framebuff_t *buff, sfVector2i *pos, int r, sfColor color)
{
    if (pos[0].x != pos[1].x)
        draw_lineX(buff, pos, r, color);
    if (pos[0].y != pos[1].y)
        draw_lineY(buff, pos, r, color);
}

void    draw_big_line(my_framebuff_t *buff, sfVector2i *pos, int f,
sfColor color)
{
    sfVector2i rec[] = {pos[0], pos[1]};
    int        ix = (pos[0].y > pos[1].y) ? 1 : -1;
    int        iy = (pos[0].x < pos[1].x) ? 1 : -1;

    if (pos[0].x == pos[1].x && pos[0].y == pos[1].y)
        return ;
    while (rec[0].x < pos[0].x + f && rec[0].x > pos[0].x - f &&
rec[0].y > pos[0].y - f && rec[0].y < pos[0].y + f) {
        draw_line(buff, rec, 1, color);
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
