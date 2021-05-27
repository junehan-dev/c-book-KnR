CC				= gcc
CFLAGS			= -Werror -Wextra -Wall
NAME			= ex1_13.out
.DEFAULT_GOAL	= all

histogram.o:
	$(CC) $(CFLAGS) -c srcs/histogram.c -o $@

.PHONY: all
all: $(NAME)

$(NAME): histogram.o
	$(CC) $(CFLAGS) -Iincludes srcs/main.c $^ -o $@

.PHONY: clean
clean:
	/bin/rm histogram.o

.PHONY: fclean
fclean:
	/bin/rm $(NAME)

.PHONY: re
re: fclean clean all
	
	
