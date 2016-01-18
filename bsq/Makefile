NAME = bsq

SRC = ft_outils.c ft_resolve_square.c ft_read_square.c ft_verif_square.c

O = ft_outils.o ft_resolve_square.o ft_read_square.o ft_verif_square.o

all : $(NAME)

$(NAME):
		gcc -c -Wall -Wextra -Werror $(SRC)
		gcc -o $(NAME) $(O)

clean:
		rm -f *o
		rm -f bsq.tmp

fclean: clean
		rm -f $(NAME)

re: fclean all
