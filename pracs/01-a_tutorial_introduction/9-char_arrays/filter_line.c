#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "char_arr.h"

ssize_t	filter_bytes(void *src)
{
	ssize_t		ret;

	ret = (strlen((const char *)src));
	return ((ret > 79) ? ret : 0);
}

int		read_and_map(const char *path)
{
	int		fd;
	char 	*dest[BUFSIZ];
	ssize_t len;
	int		i;
	

	fd = open(path, O_RDONLY);
	if (!fd)
		return (1);

	len = ft_readlines(dest, fd);
	close(fd);
	i = 0;
	while (i < len) {
		if (strmap(dest[i], filter_bytes))
			write(STDOUT_FILENO, dest[i], strlen(dest[i]));
		free(dest[i]);
		i++;
	}
	return (len);
}

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
