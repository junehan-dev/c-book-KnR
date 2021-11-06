CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
OBJECTS			= srcs/ft_strncat.o
		#srcs/ft_strncat.o
NAME			= ft_string.a
.DEFAULT_GOAL	= all

.PHONY: all
all: $(OBJECTS)

srcs/ft_strncat.o:
	$(CC) $(CFLAGS) -c srcs/ft_strncat.c -o $@

.PHONY: test
test:
	$(CC) $(CFLAGS) srcs/tests/ft_t_strncat.c srcs/ft_strncat.o -o test1.out
	./test1.out
	/bin/rm test1.out

clean:
	/bin/rm $(OBJECTS)

