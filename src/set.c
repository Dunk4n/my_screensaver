/*
** EPITECH PROJECT, 2018
** set
** File description:
** try not to segfault! good luck 
*/

#include <stdlib.h>
#include "window.h"

void    delete_framebuff(my_framebuff_t *framebuff)
{
    free(framebuff->pixels);
    free(framebuff);
}

my_framebuff_t  *my_framebuff_create(int width, int height)
{
    my_framebuff_t      *buff;

    if ((buff = malloc(sizeof(my_framebuff_t))) == NULL)
        return (NULL);
    if ((buff->pixels = malloc(sizeof(sfUint8) * width * height * 4)) == NULL) {
        free (buff);
        return (NULL);
    }
    buff->width = width;
    buff->height = height;
    return (buff);
}

my_window_t     *setwindow()
{
    my_window_t *win = malloc(sizeof(my_window_t));
    sfVideoMode     video_mode;

    win->texture = sfTexture_create(LM, HM);
    win->sprite = sfSprite_create();
    video_mode.width = LM;
    video_mode.height = HM;
    video_mode.bitsPerPixel = 32;
    win->window = sfRenderWindow_create(video_mode, "sc", sfFullscreen, NULL);
    sfSprite_setTexture(win->sprite, win->texture, sfTrue);
    sfRenderWindow_setFramerateLimit(win->window, 30);
    if ((win->buff = my_framebuff_create(LM, HM)) == NULL)
        return (NULL);
    win->clock = sfClock_create();
    return (win);
}
