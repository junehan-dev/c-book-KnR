#include <unistd.h>
#include <assert.h>
/*
 * Forward functions
 */
ssize_t		next_column(const char *src);
ssize_t		next_nonblank(const char *src);
const char	*next_paragraph(const char *src);

int		main(void)
{
	return (0);
}

const char	*next_paragraph(const char *src)
{
	size_t	i;

	i = 0;
	while (*(src + i) && *(src + i) != '\n')
		i++;

	if (!*(src + i) || !*(src + i + 1))
		return (NULL);
	return (src + i + 1);
}

ssize_t next_nonblank(const char *src)
{
	ssize_t	i;
	char	ch;

	i = 0;

	while ((ch = *(src + i))) {
		if (ch != ' ' || ch != '\t' || ch != '\n')
			return (i);
		i++;
	}

	return (-1);
}

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

