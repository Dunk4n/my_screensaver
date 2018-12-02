##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##


D_SRC	=	./src/
D_INC	=	./include/
D_LIB	=	./lib/my/

SRC	=	$(D_SRC)main.c		\
		$(D_SRC)window.c	\
		$(D_SRC)set.c		\
		$(D_SRC)display.c	\
		$(D_SRC)move.c		\
		$(D_SRC)scren1.c	\
		$(D_SRC)scren2.c	\
		$(D_SRC)scren3.c	\
		$(D_SRC)scren4.c	\
		$(D_SRC)scren5.c	\
		$(D_SRC)line.c		\
		$(D_SRC)square.c	\
		$(D_SRC)circle.c	\
		$(D_SRC)ppm.c		\
		$(D_SRC)check.c

OBJ	=	$(SRC:%.c=%.o)

NAME	=	my_screensaver

CFLAGS	=	-W -Wall -Wextra -I$(D_INC)

LDFLAGS	=	-L$(D_LIB) -lmy

all	:	$(NAME)

libmy	:
		make -C $(D_LIB)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		$(MAKE) -C $(D_LIB) fclean
		rm -f $(NAME)
		rm -f *~

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) -l csfml-graphics -l csfml-system -lm
	rm -f $(OBJ)

re	:
		$(MAKE) fclean
		$(MAKE) all

.PHONY	:	 all clean fclean re
