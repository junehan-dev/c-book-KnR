CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
NAME			= ft_str.a
OBJECTS			= srcs/ft_strjoin.o \
				srcs/ft_strndup.o \
				srcs/ft_strstr.o \
				srcs/ft_strreplace.o

.DEFAULT_GOAL	:= all

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

.PHONY: clean
clean:
	/bin/rm $(OBJECTS)

.PHONY: fclean
fclean:
	/bin/rm $(NAME)

.PHONY: tests
tests: test_strstr

.PHONY: re
re:	$(NAME) clean fclean $(NAME)

srcs/ft_strjoin.o:
	$(CC) $(CFLAGS) -c srcs/ft_strjoin.c -o $@

srcs/ft_strndup.o:
	$(CC) $(CFLAGS) -c srcs/ft_strndup.c -o $@

srcs/ft_strstr.o:
	$(CC) $(CFLAGS) -c srcs/ft_strstr.c -o $@

srcs/ft_strreplace.o:
	$(CC) $(CFLAGS) -c -Iincludes/ srcs/ft_strreplace.c -o $@

.PHONY: test_strstr
test_strstr:
	$(CC) $(CFLAGS) -Iincludes tests/$@.c $(NAME) -o $@
	./$@
	/bim/rm $@


