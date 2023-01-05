##
## EPITECH PROJECT, 2023
## myradar
## File description:
## Makefile
##

SRC =	main.c \
		array_creator.c \
		atc.c \
		displayer.c \
		geo_parse.c \
		itoa.c \
		large_plane_collider.c \
		large_plane_collider_utils.c \
		my_radar.c \
		opener.c \
		planes.c \
		planes_utils.c
SRC:= $(addprefix src/, $(SRC))

OBJ =	$(SRC:.c=.o)

LIBS = lib/libmy.a

LDFLAGS = -Llib
LDLIBS = -lmy -lm -lcsfml-graphics -lcsfml-window -lcsfml-system

CPPFLAGS = -Iinclude

CFLAGS = -O1

NAME =	my_radar

all: lib $(NAME)

$(NAME): lib $(OBJ)
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS) $(LDLIBS) $(CPPFLAGS) $(CFLAGS)

lib:
	$(MAKE) -C lib/libmy

clean:
	$(MAKE) -C lib/libmy clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C lib/libmy fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re lib
