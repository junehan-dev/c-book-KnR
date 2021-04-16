CC			= gcc
CFLAGS		= -Werror -Wall -Wextra -Iincludes
SRC			= srcs/temp_converter.c
TEST_SRC	= srcs/test_temp_converter.c
NAME		= temp_converter.o

.PHONY: all
all: $(NAME)
	@echo "default done"

$(NAME):
	$(CC) $(CFLAGS) -c -o $@ $(SRC)
	@echo "make done"

.PHONY: test
test: fclean $(NAME)
	$(CC) $(CFLAGS) -o test.run $(TEST_SRC) $(NAME)
	./test.run
	@echo "test done, remove testfile.."
	
.PHONY: clean
clean:
	@/bin/rm test.run
	@echo "clean done"

.PHONY: fclean
fclean:
	@/bin/rm $(NAME)
	@echo "fclean done"

.PHONY: re
re: clean fclean $(NAME)
	@echo "rebuild done"

