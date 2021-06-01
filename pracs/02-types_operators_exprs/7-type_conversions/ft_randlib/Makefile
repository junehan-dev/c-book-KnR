CC				= gcc
CFLAGS			= -Werror -Wall -Wextra
OBJECTS			= srcs/ft_atoi.o \
				srcs/ft_rand.o

NAME			= ft_randlib.a

.DEFAULT_GOAL	:= all

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

srcs/ft_atoi.o:
	$(CC) $(CFLAGS) -c srcs/ft_atoi.c -o $@

srcs/ft_rand.o:
	$(CC) $(CFLAGS) -c srcs/ft_rand.c -o $@

.PHONY: clean
clean:
	/bin/rm $(OBJECTS)

.PHONY: fclean
fclean:
	/bin/rm $(OBJECTS)
	/bin/rm $(NAME)

.PHONY: re
re: fclean all

