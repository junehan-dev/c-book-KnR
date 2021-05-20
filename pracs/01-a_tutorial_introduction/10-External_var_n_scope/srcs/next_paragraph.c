#include <unistd.h>

const char	*next_paragraph(const char *src)
{
	size_t	i;
	char	ch;

	i = 0;
	if ((ch = *(src + i)) == '\0' || ch == -1)
		return (NULL);

	while (ch && ch != '\n') {
		i++;
		ch = *(src + i);
	}
	if (!ch || ch == -1)
		return (NULL);

	return (src + i + 1);
}

