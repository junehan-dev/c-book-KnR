CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
NAME			= 
OBJECTS			= 
.DEFAULT_GOAL	:= all

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

convert_tab:

.PHONY: clean
clean:
	/bin/rm $(OBJECTS)

.PHONY: fclean
fclean:
	/bin/rm $(NAME)

.PHONY: re
re:	$(NAME) clean fclean $(NAME)

