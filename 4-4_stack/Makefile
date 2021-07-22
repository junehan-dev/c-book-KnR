CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
OBJECTS			= srcs/ft_stack_create.o \
				srcs/ft_stack_push.o

NAME			= ft_stack.a

.DEFAULT_GOAL	:= all

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs  $@ $^
	ranlib $@

test:
	$(CC) $(CFLAGS) -g -Iincludes test.c $(NAME) -o $@.run
	./$@.run
	@echo "TEST FIN with STATUS: " $?
	/bin/rm ./$@.run

srcs/ft_stack_create.o:
	$(CC) $(CFLAGS) -c srcs/ft_stack_create.c -o $@

srcs/ft_stack_push.o:
	$(CC) $(CFLAGS) -c srcs/ft_stack_push.c -o $@

.PHONY: clean
clean:
	/bin/rm $(OBJECTS)

.PHONY: fclean
fclean:
	/bin/rm $(NAME)

.PHONY: re
re: clean fclean all

