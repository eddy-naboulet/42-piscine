NAME = ft_display_file

SRC = ft_display_file.c

SRC_B = ft_display_file.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc -o $(NAME) $(SRC_B)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
