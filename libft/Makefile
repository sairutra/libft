include sources.mk

CC = cc

CFLAGS = -Wall -Werror -Wextra

BNS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SOURCES:.c=.o)

B-OBJS = $(BNS:.c=.o)

NAME = libft.a

LIB_DIR = libft

all: $(NAME) bonus

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

 %.o: %.c
	@$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@rm -f $(OBJS)
	@rm -f $(B-OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(B-OBJS)
	@ar rcs $(NAME) $(B-OBJS)
