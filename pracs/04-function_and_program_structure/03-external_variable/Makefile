CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
NAME			= ft_calc.a
PROGRAM			= ft_calc.out
OBJECTS			= srcs/ft_token.o\
				srcs/ft_atoi.o
.DEFAULT_GOAL	:= all

$(NAME): $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

.PHONY: all
all: $(PROGRAM)

$(PROGRAM): $(NAME)
	$(CC) $(CFLAGS) -Iincludes ./srcs/ft_calc.c $^ -o $@

.PHONY: build
build: $(NAME)

srcs/ft_token.o:
	$(CC) $(CFLAGS) srcs/ft_token.c -c -o $@

srcs/ft_atoi.o:
	$(CC) $(CFLAGS) srcs/ft_atoi.c -c -o $@

.PHONY: clean
clean:
	/bin/rm $(OBJECTS)

.PHONY: fclean
fclean:
	/bin/rm $(PROGRAM)
	/bin/rm $(NAME)

.PHONY: re
re: clean fclean $(PROGRAM)

