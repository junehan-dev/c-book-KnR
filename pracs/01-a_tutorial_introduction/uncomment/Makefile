CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
NAME			= c-uncomment
OBJECTS			=

.DEFAULT_GOAL	:= all

.PHONY: all
all: $(NAME) $(PROGRAMS)

$(NAME): $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

.PHONY: clean
clean:
	/bin/rm $(OBJECTS)
	echo "DO clean"

.PHONY: fclean
fclean:
	echo "DO fclean"
	/bin/rm $(NAME)
	/bin/rm $(PROGRAMS)

.PHONY: re
re:	clean fclean all

