NAME = ft_cat

SRC = ft_cat.c

SRC_B = ft_cat.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc -o $(NAME) $(SRC_B)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
