CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
NAME			= char_arr.a
OBJECTS			= srcs/strmap.o
.DEFAULT_GOAL	:= all


.PHONY: all
all: build

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

.PHONY: clean
clean:
	/bin/rm $(OBJECTS)

.PHONY: fclean
fclean:
	/bin/rm $(NAME)

.PHONY: re
re: clean fclean $(NAME)

# SRCS
srcs/strmap.o:
	$(CC) $(CFLAGS) -c srcs/strmap.c -o $@

