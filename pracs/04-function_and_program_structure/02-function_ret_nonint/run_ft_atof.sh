#!/bin/bash
gcc -Wall -Wextra -Werror ./srcs/ft*.c -o ft_atof.out
./ft_atof.out $1
/bin/rm ./ft_atof.out
