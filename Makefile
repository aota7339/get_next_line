NAME	=	gnl.a
SRCS	=	get_next_line.c \
			get_next_line_utils.c \
			main.c
OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=1

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o:	
		$(CC) $(CFLAGS) -c $(SRCS)

clean:
		rm -f $(OBJS)

fclean:
		rm -f $(OBJS)
		rm -f $(NAME)

re:		fclean all

.PHONY:	clean fclean re all