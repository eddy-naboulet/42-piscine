NAME = ft_hexdump

SRC = ft_display.c ft_outils.c ft_hxd.c

O = ft_display.o ft_outils.o ft_hxd.o

all : $(NAME)

$(NAME):
		gcc -c -Wall -Wextra -Werror $(SRC)
		gcc -o $(NAME) $(O)

clean:
		rm -f *.o
		rm -f filebis

fclean: clean
		rm -f $(NAME)

re: fclean all
