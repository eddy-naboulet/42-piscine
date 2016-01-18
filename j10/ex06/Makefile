NAME = do-op

SRC = ft_do_op.c ft_math.c main.c

SRC_B = ft_do_op.o ft_math.o main.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc -o $(NAME) $(SRC_B)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
