#include <stdlib.h>
#include "ft_string.h"

size_t	ft_strlen(const char *s)
{
	size_t	ret;

	ret = 0;
	while (*s++)
		ret++;

	return (ret);
}


char	*ft_strreplace(const char *s, const char *from, const char *to)
{
	char		*buf[BUFSIZ];
	char		**buf_pt;
	char		*next;
	const char	*prev;
	int			len;

	prev = (char *)s;
	if (!(next = (ft_strstr(prev, from))))
		return (0);

	buf_pt = buf;
	len = ft_strlen(from);
	while (next) {
		*buf_pt++ = ft_strndup(prev, next - prev);
		prev = next + len;
		next = ft_strstr(prev, from);
	}

	*buf_pt = 0;
	buf_pt = buf;
	next = *buf_pt;
	while (*(buf_pt + 1)) {
		next = ft_strjoin(next, to);
		next = ft_strjoin(next, *(buf_pt + 1));
		free((void*)*buf_pt++);
	}
	next = ft_strjoin(next, *buf_pt);
	free((void*)*buf_pt);
	return (next);
}
