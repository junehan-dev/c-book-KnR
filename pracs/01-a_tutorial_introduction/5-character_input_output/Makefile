CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
SOURCES			= get_eof.run

.DEFAULT_GOAL	:= all

.PHONY: all
all: build

build: $(SOURCES)

get_eof.run:
	$(CC) $(CFLAGS)	-o $@ srcs/get_eof.c

.PHONY: fclean
fclean:
	/bin/rm ./*.run
