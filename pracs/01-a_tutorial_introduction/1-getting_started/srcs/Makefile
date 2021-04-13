CC		= gcc
CFLAGS	= -Werror -Wall -Wextra
SRCS	= 1-1_hello_world 1-2_escape_c

.DEFAULT_GOAL = all

.PHONY: all
all: $(SRCS)

1-1_hello_world:
	$(CC) $(CFLAGS) $@.c -o $@.out

1-2_escape_c:
	$(CC) $(CFLAGS) $@.c -o $@.out

.PHONY:	clean
clean:
	/bin/rm ./*.out
