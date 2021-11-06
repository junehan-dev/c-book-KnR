CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
OBJECTS			= srcs/ft_strncat.o \
				srcs/ft_strncmp.o \
				srcs/ft_strncpy.o
NAME			= ft_string.a
.DEFAULT_GOAL	= all

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

srcs/ft_strncat.o:
	$(CC) $(CFLAGS) -c srcs/ft_strncat.c -o $@
srcs/ft_strncmp.o:
	$(CC) $(CFLAGS) -c srcs/ft_strncmp.c -o $@
srcs/ft_strncpy.o:
	$(CC) $(CFLAGS) -c srcs/ft_strncpy.c -o $@


.PHONY: test
test:
	$(CC) $(CFLAGS) srcs/tests/ft_t_strncat.c $(NAME) -o test1.out
	$(CC) $(CFLAGS) srcs/tests/ft_t_strncmp.c $(NAME) -o test2.out
	$(CC) srcs/tests/ft_t_strncpy.c $(NAME) -o test3.out
	./test1.out
	/bin/rm test1.out
	./test2.out
	/bin/rm test2.out
	./test3.out
	/bin/rm test3.out

.PHONY: clean
clean:
	/bin/rm $(OBJECTS)
	/bin/rm ./test*.out

.PHONY: fclean
fclean:
	/bin/rm $(NAME)
