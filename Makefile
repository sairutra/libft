# This is the $(CC) Macro that indicates 
# the compiler that we are using which is cc

CC = cc

# This is the $(CFLAGS) Macro that indicates 
# which flags we use in combination with $(CC) macros

CFLAGS = -Wall -Werror -Wextra

# This is the $(SRCS) Macro that indicates 
# which files we want to compile in this makefile

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		ft_substr.c ft_tolower.c ft_toupper.c

BNS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# These objects are dependent on the sources macro
# This syntax means that it replaces all the .c to .o
# when the $(OBJS) macro is called.

OBJS = $(SRCS:.c=.o)

B-OBJS = $(BNS:.c=.o)

# This is the $(NAME) macro that is equivalent to the 
# libft.a file.

NAME = libft.a

# This all is rule that is dependent on $(NAME) rule
# because it is the first command in the makefile, it will be 
# triggered when we call "make" in the terminal

all: $(NAME)

# This is a rule that is called $(NAME), which is dependent on
# $(OBJS), which once it's updates, fires the ar command to 
# (r)eplace files in archive that been changed, (c) create new 
# files if they did not exist yet, and reindex(s) the archive
# to make it easier to locate files

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# all command is dependent on .o files existing, so this rule
# will make sure to (re)create them if neccessary. This rule is a 
# a pattern rule ‘%.o : %.c’ that says how to make any file stem.o 
# from another file stem.c. It uses the automatic variable $@ for 
# source file which is %.o and $< for each target file which is %.c
# and it will apply this rule for each case. -c is to make object files
# and -o to then name those .o files.

 %.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@

# This rule has a phony target. The command 
# will forcefully remove all elements that are in 
# $(OBJS) macro.

clean:
	rm -f $(OBJS)
	rm -f $(B-OBJS)

# This rule has a target which is clean
# This will make sure clean is up to date and 
# execute it's commands before, it cleans the 
# $(NAME) macro

fclean: clean
	rm -f $(NAME)

# This rule has a target which is fclean
# This will make sure fclean is up to date and 
# execute it's commands before. Then it will do the
# same with all.

re: fclean all

bonus: $(B-OBJS)
	ar rcs $(NAME) $(B-OBJS)