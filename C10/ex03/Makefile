NAME	= ft_hexdump

SRCS	= ft_hexdump.c ft_hexdump_read.c ft_hexdump_error.c ft_hexdump_print.c ft_hexdump_dump.c ft_hexdump_canon.c
OBJS	= $(SRCS:.c=.o)

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c ft_hexdump.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re