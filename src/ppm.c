/*
** EPITECH PROJECT, 2018
** ppm
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "window.h"
#include "my.h"

/*int     config(char *str, int nb)
{
    char    buff[4096];
    int     fd;
    int     size = 1;
    int     i = 0;
    char    **tab;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        return (-1);
    size = read(fd, buff, 4906);
    buff[size] = '\0';
    close(fd);
    tab = my_str_to_word_array(buff);
    while (tab[i] != 0)
        i++;
    return ((i < nb) ? -1 : my_getnbr(tab[nb] + ((nb == 0) ? 1 : 0)));
}

void    read_color(sfColor **tab, char *buff, int i, int j)
{
    int n = 0;

    while (buff[n] != '\0') {

        n++;
    }
}

sfColor **get_color(sfColor **tab, char *str)
{
    char    *buff = malloc(4096);
    int     fd;
    int     size = 1;
    int     i = 0;
    int     j = 0;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        return (-1);
    size = read(fd, buff, 4095);
    buff[size] = '\0';
    while (size != 0) {
        size = read(fd, buff, 4095);
        buff[size] = '\0';
        read_color(tab, buff, i, j);
    }
}

sfColor **ppm(char *str)
{
    int     x = config(str, 1);
    int     y = config(str, 2);
    sfColor **tab = malloc(sizeof(sfColor*) * x);
    int     i = 0;

    while (i < x) {
        tab[i] = malloc(sizeof(sfColor) * y);
        i++;
    }
    return (get_color(tab, str));
}*/
