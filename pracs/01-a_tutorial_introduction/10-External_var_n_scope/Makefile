CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
#NAME			= 
PROGRAMS		= print_longest \
				detab
.DEFAULT_GOAL	:= all

.PHONY: all
all: $(PROGRAMS)

$(NAME):

.PHONY: print_longest
print_longest:
	$(CC) $(CFLAGS) srcs/$@.c -o $@

.PHONY: detab
detab:
	$(CC) $(CFLAGS) srcs/$@.c -o $@

.PHONY: clean
clean:
	echo "DO clean"

.PHONY: fclean
fclean:
	echo "DO fclean"
	/bin/rm $(PROGRAMS)

.PHONY: re
re:	$(all) clean fclean $(NAME)

