#include <unistd.h>

const char	*next_paragraph(const char *src)
{
	size_t	i;

	i = 0;
	while (*(src + i) > 1 && *(src + i) != '\n')
		i++;

	if (*(src + i) == '\n')
		return (src + i + 1);
	return (NULL);
}

