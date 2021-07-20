#include "ft_additionals.h"
#include <assert.h>

ssize_t	get_str(char *buf)
{
	ssize_t		rb;

	rb = read(STDIN_FILENO, buf, MAXLEN);
	return (rb);
}


ssize_t	clean_split(void **srcs)
{
	ssize_t	len;
	char **src_pt;

	len = 0;
	src_pt = (char **)srcs;
	while (*src_pt)
	{
		free(*src_pt++);
		len++;
	}
	return (len);
}

char	*split_and_join(char *dest, char *src)
{
	char	**splited;
	char	**splited_pt;
	char	len;

	len			= 1;
	splited		= ft_split(src, ' ');
	splited_pt	= splited;
	dest		= *splited_pt++;

	if (*splited_pt)
		while (*splited_pt) {
			dest = ft_strjoin((const char *)dest, " \0");
			dest = ft_strjoin((const char *)dest, (const char *)*splited_pt++);
			len++;
		}
	assert(len == clean_split((void **)splited));
	return (dest);
}


int		main(void)
{
	char	buf[MAXLEN];
	char	*ret;

	get_str(buf);
	ret = NULL;
	ret = split_and_join(ret, buf);
	write(STDOUT_FILENO, ret, strlen(ret));
	free(ret);
	return (0);
}


