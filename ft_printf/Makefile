LIB_DIR := libft

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = libftprintf.c ft_printchar.c ft_printstr.c \
	ft_printint.c ft_printuint.c ft_printamp.c ft_printhex.c \
	ft_hexconvert.c ft_printptr.c ft_hexconvertptr.c 

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

 %.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
