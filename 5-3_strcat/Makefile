CC				= gcc
CFLAGS			= -Wall -Wextra -Werror 	
OBJECT			= srcs/ft_strcat.o
NAME			= concat-strs.run
.DEFAULT_GOAL	= all

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(CFLAGS) srcs/strcat-test.c $^ -o $@

srcs/ft_strcat.o:
	$(CC) $(CFLAGS) -c srcs/ft_strcat.c -o $@

.PHONY: clean
clean:
	/bin/rm $(OBJECT) $(NAME)

