NAME = ft_tail

SRC = ft_tail.c ft_atoi.c

O = ft_tail.o ft_atoi.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc -o $(NAME) $(O)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
