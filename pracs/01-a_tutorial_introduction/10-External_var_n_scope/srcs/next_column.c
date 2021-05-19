#include <unistd.h>

ssize_t next_column(const char *src)
{
	ssize_t	i;
	char ch;

	i = 0;
	while ((ch = *(src + i)) > 0) {
		if (ch == '.') {
			if ((ch = *(src + i + 1)) == ' ' || ch == '\t')
				return (i);
		} 
		i++;
	}

	return (-1);
}

