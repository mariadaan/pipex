NAME		=	pipex

SRCS		=	errors.c		\
				pipex.c

HEADER		=	pipex.h

OBJS		=	$(SRCS:.c=.o)

LIBFT		=	libft.a
LIBFTDIR	=	./libft/

CC			=	gcc
CFLAGS		=	-g  -Wall -fsanitize=address # -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	make -C ./libft/
	rm -f file_out
	$(CC) $(CFLAGS) $(LIBFTDIR)$(LIBFT) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -Imlx -c $< -o $@

clean:
	# find src -name "*.o" -type f -delete
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f file_out
	rm -f $(MLX)

re: fclean all

pipe:
	make
	./pipex file_in "cat -e" "grep FANTASTISCH" file_out

.PHONY: all clean fclean re debug
