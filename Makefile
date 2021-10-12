NAME		=	pipex

SRCS		=	main.c		\
				pipex.c		\
				parse.c		\
				errors.c

HEADER		=	pipex.h

OBJS		=	$(SRCS:.c=.o)

LIBFT		=	libft.a
LIBFTDIR	=	./libft/

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I .

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	make -C ./libft/
	$(CC) $(CFLAGS) $(LIBFTDIR)$(LIBFT) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f file_out
	rm -f $(MLX)

re: fclean all

pipe:
	make
	./pipex files_in/file_in "cat -e" "grep FANTASTISCH" files_out/file_out

.PHONY: all clean fclean re debug
