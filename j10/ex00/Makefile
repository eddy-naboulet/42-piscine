NAME = libft.a

SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c \
srcs/ft_swap.c

SRC_B = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) -I includes
	ar rc $(NAME) $(SRC_B)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
