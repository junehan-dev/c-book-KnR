CC              = gcc
CFLAGS          = -Wall -Werror -Wextra 
NAME            = main
.DEFAULT_GOAL    := all
OBJECTS         = ft_atof.o get_line.o

ft_atof.o: ft_atof.c
	$(CC) $(CFLAGS) -c ft_atof.c

get_line.o: get_line.c
	$(CC) $(CFLAGS) -c get_line.c

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) main_nonheader.c $^ -o $@

.PHONY: clean
clean:
	/bin/rm $(OBJECTS) $(NAME)
