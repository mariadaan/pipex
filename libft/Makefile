# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mdaan <mdaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/31 11:56:32 by mdaan         #+#    #+#                  #
#    Updated: 2021/05/25 12:03:08 by mdaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=	$(wildcard ./ascii/*.c)				\
			$(wildcard ./mem/*.c)				\
			$(wildcard ./put/*.c)				\
			$(wildcard ./str/*.c)				\
			$(wildcard ./lst/*.c)				\
			$(wildcard ./debug/*.c)				\
			$(wildcard ./read/*.c)

OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)
LIBC	=	ar -rcs
RM		=	rm -f
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
			${LIBC} $(NAME) $(OBJS)

%.o:		%.c libft.h
			$(CC) -c $(FLAGS) $< -o $@

clean:
			${RM} $(OBJS) $(OBJS_B)

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
