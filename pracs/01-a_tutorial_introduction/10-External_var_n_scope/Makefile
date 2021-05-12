CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
OBJECT			= srcs/ft_tab.o
NAME			= convert_tab
.DEFAULT_GOAL	:= all

.PHONY: all
all: $(NAME)

$(OBJECT):
	$(CC) $(CFLAGS) -c srcs/ft_tab.c -o $@

$(NAME): $(OBJECT)
	$(CC) $(CFLAGS) -Iincludes srcs/$@.c $^ -o $@

.PHONY: clean
clean:
	/bin/rm $(OBJECT)

.PHONY: fclean
	/bin/rm $(NAME)

.PHONY: re
re:	$(NAME) clean fclean $(NAME)
