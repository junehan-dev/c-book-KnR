#include <unistd.h>

ssize_t next_column(const char *src)
{
	ssize_t	i;
	char ch;

	i = 0;
	
	while ((ch = *(src + i)) && ch != '.' && ch != '\n')
		i++;

	if (ch == '.') {
		while ((ch = *(src + i)) != '.')
			i++;
	} else
		i = -1;

	return (i);
}

