#include <unistd.h>

size_t next_column(const char *src)
{
	size_t	i;
	char 	ch;

	i = 0;
	if ((ch = *src) == '\n')
		return (1);
	while (ch > 0) {
		if (ch == '.') {
			if ((ch = *(src + i + 1)) == ' ' || ch == '\t' || ch == '\n')
				return (i);
		} else if (ch == '\n') {
			return (i);
		}
		ch = *(src + ++i);
	}

	return (i);
}

