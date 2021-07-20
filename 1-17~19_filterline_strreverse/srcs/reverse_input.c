#include "char_arr.h"
#include <stdio.h>


int main(int argc, const char *argv[])
{
	int 	i;
	char	buf[BUFSIZ];
	ssize_t	len;

	i = 0;
	while (++i < argc) {
		if ((len = ft_str_reverse(buf, argv[i])))
			write(STDOUT_FILENO, buf, len);
		else
			return (1);
	}

	return (0);
}

