CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
NAME			= uncomment.a
OBJECTS			= srcs/strcomment.o \
				srcs/del_content.o
PROGRAM			= uncomment

.DEFAULT_GOAL	:= all

.PHONY: all
all: $(NAME) $(PROGRAM)

$(NAME): $(OBJECTS) 
	ar rcs $@ $^
	ranlib $@

$(PROGRAM):
	$(CC) $(CFLAGS) -Iincludes srcs/uncomment.c $(NAME) -o $@

.PHONY: clean
clean:
	/bin/rm $(OBJECTS)
	echo "DO clean"

.PHONY: fclean
fclean:
	echo "DO fclean"
	/bin/rm $(NAME)
	/bin/rm uncomment

.PHONY: re
re:	clean fclean all

srcs/strcomment.o:
	$(CC) $(CFLAGS) -c srcs/strcomment.c -o srcs/strcomment.o

srcs/del_content.o:
	$(CC) $(CFLAGS) -c srcs/del_content.c -o srcs/del_content.o
