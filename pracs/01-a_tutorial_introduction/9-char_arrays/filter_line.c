#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "char_arr.h"
#define BUFSIZ 4096


ssize_t	filter_bytes(void *src)
{
	ssize_t		ret;

	ret = (strlen((const char *)src));
	return ((ret > 12) ? ret : 0);
}

int		read_and_map(const char *filename)
{
	int		fd;
	char 	*dest[BUFSIZ];
	ssize_t len;
	int		i;
	

	fd = open(filename, O_RDONLY);
	if (!fd)
		return (1);
	len = ft_readlines(dest, fd);
	write(STDOUT_FILENO, "hi\n", 3);
	i = 0;
	while (i < len) {
		if (strmap(dest[i], filter_bytes)) {
			write(STDOUT_FILENO, dest[i], strlen(dest[i]));
			write(STDOUT_FILENO, "\nby\n", 4);
		}
		free(dest[i]);
		i++;
	}
	close(fd);
	return (len);
}

#include <stdio.h>
int		main(int argc, const char *argv[])
{
	int	i;
	if (argc == 1)
		return (0);
	
	i = 1;
	while (i < argc)
		read_and_map(argv[i++]);
	return (0);
}
