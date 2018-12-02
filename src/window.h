/*
** EPITECH PROJECT, 2018
** window
** File description:
** window
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>

typedef struct  my_framebuff_s
{
    int         width;
    int         height;
    sfUint8     *pixels;
}               my_framebuff_t;

typedef struct  my_window_s
{
    sfRenderWindow      *window;
    sfEvent             event;
    sfTexture           *texture;
    sfSprite            *sprite;
    my_framebuff_t      *buff;
    sfVector2u          pos;
    sfClock             *clock;
    sfInt32             time;
    int                 tmp;
}               my_window_t;

int             window();
void            delete_framebuff(my_framebuff_t *framebuff);
my_framebuff_t  *my_framebuff_create(int width, int height);
int             check(my_window_t *win);
void            update(my_window_t *win);
void            put_pixel(my_framebuff_t *framebuff,
int x, int y, sfColor color);
void            draw_square(my_framebuff_t *buff, sfVector2u pos,
unsigned int size, sfColor color);
void            draw_vbord(my_framebuff_t *buff, sfVector2u pos, int r,
sfColor color);
my_window_t     *setwindow();
void            draw_vinyl(my_framebuff_t *buff, sfVector2u pos, int *tab,
sfColor color);
my_framebuff_t  *rotate(my_framebuff_t *buff, float angl, sfVector2u pos,
int r);
void            clean(my_framebuff_t *buff);
int             vinyl(int *nb_scren, my_window_t *win);
void            draw_line(my_framebuff_t *buff, sfVector2i *pos, int r,
sfColor color);
void            draw_big_line(my_framebuff_t *buff, sfVector2i *pos, int force,
sfColor color);
void            draw_circle(my_framebuff_t *buff, sfVector2i cnt, int *tab,
sfColor color);
int     jeux_olym(int *nb_scren, my_window_t *win);
int     binary(int *nb_scren, my_window_t *win);
void    draw_olym(my_window_t *win, sfVector2i  *pos, int **tab);
void    draw_cadre(my_window_t *win);
void    anime(int *tab[6], int *cnt);
void    asign(int **tab);
void    square(my_framebuff_t *buff, sfVector2f pos, sfVector2i size,
sfColor color);
int     img(int *nb_scren, my_window_t *win);
sfColor **ppm(char *str);
void    draw_blob(my_framebuff_t *buff, sfVector2i cnt, int r, sfColor color);
void    put_add_pixel(my_framebuff_t *framebuff, int x, int y, sfColor color);
my_framebuff_t  *blurring(my_framebuff_t *buff, sfVector2u pos, int r);
int     infinit(int *nb_scren, my_window_t *win);

# define LM 1920
# define HM 1080
# define NBS 4

#endif
