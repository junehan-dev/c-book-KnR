#include <unistd.h>

int			is_col_delimiter(char next)
{
	if (next == ' ' || next == '\t')
		return (1);

	return (0);
}

const char	*next_column(const char *src)
{
	size_t	i;
	char	ch;

	i = 0;

	while ((ch = *(src + i)) != '.' && ch && ch != '\n')
		i++;

	if (ch == '.' && is_col_delimiter(*(src + i + 1)))
		return (src + i + 1);

	return (NULL);
}

