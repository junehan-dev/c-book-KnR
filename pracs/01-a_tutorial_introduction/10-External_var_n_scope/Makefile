CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
NAME			= ft_extern.a
PROGRAMS		= print_longest \
				detab \
				entab
OBJECTS			= srcs/copy.o \
				srcs/get_line.o \
				srcs/fstring.o \
				srcs/next_paragraph.o \
				srcs/next_column.o \
				srcs/next_nonblank.o 

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

.PHONY: srcs/fstring.o
srcs/fstring.o:
	$(CC) $(CFLAGS) -c srcs/fstring.c -o $@

.PHONY: srcs/next_paragraph.o
srcs/next_paragraph.o:
	$(CC) $(CFLAGS) -c srcs/next_paragraph.c -o $@

.PHONY: srcs/next_column.o 
srcs/next_column.o:
	$(CC) $(CFLAGS) -c srcs/next_column.c -o $@

.PHONY: srcs/next_nonblank.o 
srcs/next_nonblank.o:
	$(CC) $(CFLAGS) -c srcs/next_nonblank.c -o $@

