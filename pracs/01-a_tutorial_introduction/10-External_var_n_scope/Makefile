CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
NAME			= ft_extern.a
PROGRAMS		= print_longest \
				detab 
				#entab
OBJECTS			= srcs/copy.o \
				srcs/get_line.o

.DEFAULT_GOAL	:= all

.PHONY: all
all: $(NAME) $(PROGRAMS)

$(NAME): $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

.PHONY: entab
entab:
	$(CC) $(CFLAGS) srcs/$@.c -o $@

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
re:	$(all) clean fclean $(all)

.PHONY: print_longest
print_longest:
	$(CC) $(CFLAGS) srcs/$@.c -o $@

.PHONY: detab
detab:
	$(CC) $(CFLAGS) -Iincludes srcs/$@.c $(NAME) -o $@

.PHONY: entab
entab:
	$(CC) $(CFLAGS) -Iincludes srcs/$@.c $(NAME) -o $@

.PHONY: srcs/copy.o
srcs/copy.o:
	$(CC) $(CFLAGS) -c srcs/copy.c -o $@

.PHONY: srcs/get_line.o
srcs/get_line.o:
	$(CC) $(CFLAGS) -c srcs/get_line.c -o $@

