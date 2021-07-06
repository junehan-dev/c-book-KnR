#!/bin/bash
gcc -Wall -Werror -Wextra -c ./srcs/ft_itoa.c -o ./ft_itoa.o
gcc -Wall -Werror -Wextra ./srcs/ft_itoa_format.c ./ft_itoa.o -o ./ft_itoa_format.out

if [ $2 ] 
then
	./ft_itoa_format.out $1 $2
else
	echo "NO input provided"
fi
/bin/rm ./ft_itoa.o ./ft_itoa_format.out
