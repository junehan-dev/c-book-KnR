#include <unistd.h>

const char	*next_paragraph(const char *src)
{
	size_t	i;

	i = 0;
	if (!*src || *src == -1)
		return (NULL);

	while (*(src + i) && *(src + i) != '\n')
		i++;

	if (*(src + i) == '\n')
		return (src + i + 1);
	return (src + i);
}

