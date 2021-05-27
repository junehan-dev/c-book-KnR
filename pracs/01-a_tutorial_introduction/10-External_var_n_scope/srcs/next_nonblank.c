#include <unistd.h>

ssize_t next_nonblank(const char *src)
{
	ssize_t	i;
	char	ch;

	i = 1;

	while ((ch = *(src + i))) {
		if (ch != ' ' || ch != '\t' || ch != '\n')
			return (i);
		i++;
	}

	return (-1);
}

