CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
NAME			= char_arr.a
OBJECTS			= srcs/strmap.o \
				srcs/ft_str_next_split.o \
				srcs/ft_str_reverse.o
PROGS			= filter_line.run \
				reverse_input.run
.DEFAULT_GOAL	:= all


.PHONY: all
all: build $(PROGS)

.PHONY: test
test:
	$(CC) $(CFLAGS) -Iincludes tests/test_all.c $(NAME) -o test.run
	./test.run
	/bin/rm test.run

.PHONY: build
build: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

	
filter_lines: 

.PHONY: clean
clean:
	/bin/rm $(OBJECTS)

.PHONY: fclean
fclean:
	/bin/rm $(NAME)
	/bin/rm $(PROGS)

.PHONY: re
re: $(NAME) clean fclean
	$(MAKE) $(NAME)
	$(MAKE) $(PROGS)

# SRCS
srcs/strmap.o:
	$(CC) $(CFLAGS) -c srcs/strmap.c -o $@

srcs/ft_str_next_split.o:
	$(CC) $(CFLAGS) -c srcs/ft_str_next_split.c -o $@

srcs/ft_str_reverse.o:
	$(CC) $(CFLAGS) -c srcs/ft_str_reverse.c -o $@

# Programs
filter_line.run:
	$(CC) $(CFLAGS) -g -Iincludes srcs/filter_line.c $(NAME) -o $@

reverse_input.run:
	$(CC) $(CFLAGS) -g -Iincludes srcs/reverse_input.c $(NAME) -o $@
