SRCS	=	main.c				\
			get_next_line.c		\
			get_next_line_utils.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=2

$(NAME)	:	$(OBJS)
			gcc $(OBJS)

all		:	$(NAME)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
