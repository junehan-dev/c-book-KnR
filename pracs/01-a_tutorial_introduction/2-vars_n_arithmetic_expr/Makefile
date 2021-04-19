CC			= gcc
CFLAGS		= -Werror -Wall -Wextra -Iincludes
SRC			= srcs/temp_converter.c
TEST_SRC	= srcs/test_temp_converter.c
OBJ			= temp_converter.o
NAME		= celtofhar.out

.PHONY: all
all: $(NAME)
	@echo "default done"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) srcs/main.c $^ -o $@ 

$(OBJ):
	$(CC) $(CFLAGS) -c -o $@ $(SRC)
	@echo "made object"

.PHONY: test
test: fclean $(OBJ)
	$(CC) $(CFLAGS) -o test.run $(TEST_SRC) $(OBJ)
	./test.run
	@echo "test done, remove testfile.."
	@/bin/rm test.run
	
.PHONY: clean
clean:
	@/bin/rm $(OBJ)

.PHONY: fclean
fclean:
	@/bin/rm $(NAME)

.PHONY: re
re: clean fclean $(NAME)
	@echo "rebuild done"

