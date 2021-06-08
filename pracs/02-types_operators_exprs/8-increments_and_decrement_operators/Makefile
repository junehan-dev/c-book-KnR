CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
OBJECTS			= srcs/ft_squeeze.o
.DEFAULT_GOAL	:= all

.PHONY: all
all: $(OBJECTS)

srcs/ft_squeeze.o:
	$(CC) $(CFLAGS) -c srcs/ft_squeeze.c -o $@

.PHONY: clean
clean:
	/bin/rm $(OBJECTS)
