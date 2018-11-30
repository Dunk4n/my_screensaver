/*
** EPITECH PROJECT, 2018
** main
** File description:
** try not to segfault, good luck :)
*/

#include "my.h"
#include "window.h"

int     non(int ac)
{
    my_printf("./my_screensaver: bad arguments: %d", ac - 1);
    my_printf(" given but 1 is required\nretry with -h\n");
    return (84);
}

int     flagh(void)
{
    my_printf("animation rendering in a CSFML window.\n\nUSAGE\n");
    my_printf("./my_screensaver [OPTIONS] animation_id\nanimation_id");
    my_printf("    ID of the animation to process (between 1 and 2).");
    my_printf("\n\nOPTIONS\n-d                print the description");
    my_printf("of all the animations and quit.\n-h                p");
    my_printf("rint the usage and quit.\n\nUSER INTERACTIONS\nLEFT_ARROW");
    my_printf("        switch to the previous animation.\nRIGHT_ARROW");
    my_printf("       switch to the next animation.\n");
    return (0);
}

int     flagd(void)
{
    my_printf("1: vinyl.\n");
    my_printf("2: jeux olympiques.\n");
    return (0);
}

int     main(int ac, char **av)
{
    if (ac != 2)
        return (non(ac));
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        return (flagh());
    if (av[1][0] == '-' && av[1][1] == 'd' && av[1][2] == '\0')
        return (flagd());
    if (my_getnbr(av[1]) >= 1 && my_getnbr(av[1]) <= 2)
        return (window(my_getnbr(av[1]) - 1));
    return (84);
}
