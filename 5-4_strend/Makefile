CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
OBJECTS			= srcs/ft_strstr.o\
				srcs/ft_strcmp.o\
				srcs/ft_strend.o
NAME			= ft_strend.a
.DEFAULT_GOAL	= all

.PHONY: all
all: $(NAME)
	$(CC) $(CFLAGS) -Iincludes srcs/run_strend.c ft_strend.a -o run_strend.out

$(NAME): $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

srcs/ft_strstr.o:
	$(CC) $(CFLAGS) -c srcs/ft_strstr.c -o $@

srcs/ft_strcmp.o:
	$(CC) $(CFLAGS) -c srcs/ft_strcmp.c -o $@

srcs/ft_strend.o:
	$(CC) $(CFLAGS) -c srcs/ft_strend.c -o $@

.PHONY: clean
clean:
	/bin/rm $(OBJECTS) $(NAME) ./run_strend.out
