#!/bin/bash
gcc -Wall -Werror -Wextra ./srcs/ft_itob.c -o ./ft_itob.out
if [ $2 ] 
then
	./ft_itob.out $1 $2
elif [ $1 ]
then
	./ft_itob.out $1
else
	echo "NO input provided"
fi
/bin/rm ./ft_itob.out
