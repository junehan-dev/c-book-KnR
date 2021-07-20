#include <unistd.h>
#include <assert.h>
#include <stdlib.h>

char	*render_horizontal_bar(int occurences)
{
	char	*ret;
	int		cnt;

	ret = malloc(sizeof(char) * occurences + 2);
	if (!ret)
		return (NULL);

	cnt = 0;
	while (cnt < occurences)
		*(ret + cnt++) = '|';

	*(ret + cnt++) = '\n';
	*(ret + cnt) = '\0';
	return (ret);
}

int		print_bar(const char *src, ssize_t len)
{
	ssize_t ret;

	ret = write(STDOUT_FILENO, src, len + 1);
	assert(ret == (len + 1));
	return (ret);
}

