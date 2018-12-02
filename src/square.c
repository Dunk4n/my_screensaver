/*
** EPITECH PROJECT, 2018
** square
** File description:
** try not to segfault, good luck :)
*/

#include "window.h"

void    square(my_framebuff_t *buff, sfVector2f pos, sfVector2i size,
sfColor color)
{
    int i = 0;
    int j = 0;

    while (i < size.y) {
        j = 0;
        while (j < size.x) {
            put_pixel(buff, pos.x + j, pos.y + i, color);
            j++;
        }
        i++;
    }
}
