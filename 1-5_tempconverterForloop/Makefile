CC					= gcc
CFLAGS				= -Wall -Wextra -Werror -Iincludes
NAME				= print_temp_table.run
SRC					= srcs/main.c
OBJ					= temp_converter.o
lib_temp_converter	:= ../1-2_tempconverter
.DEFAULT_GOAL		= all

.PHONY: all
all: $(NAME)

$(NAME): $(lib_temp_converter)
	$(CC) $(CFLAGS) $(SRC) $(OBJ) -o $@

.PHONY: $(lib_temp_converter)
$(lib_temp_converter):
	$(MAKE)	temp_converter.o --directory=$@ 
	mv $@/$(OBJ) ./$(OBJ)

.PHONY:	clean
clean:
	/bin/rm $(OBJ)

.PHONY: fclean
fclean:
	/bin/rm $(NAME)

