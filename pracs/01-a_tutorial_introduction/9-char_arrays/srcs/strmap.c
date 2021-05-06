#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef	ssize_t	(*callback) (void *src);
void		*strmap(const char *src, callback cmp_func)
{
	if (cmp_func((void *)src))
		return ((void *)src);

	return (NULL);
}

char		*get_next_line(const char *src)
{
	static const char	*src_pt;
	ssize_t 			i;

	if (!src) {
		if (src_pt)
			src_pt = NULL;	
		return (NULL);
	} else {
		if (!src_pt)
			src_pt = src;

		while (*src_pt++ == '\n');

		if (!*src_pt) {
			src_pt = NULL;	
			return (NULL);
		}

		i = 0;
		while (*src_pt != '\n' && *src_pt) {
			i++;
			src_pt++;
		}

		return strndup(src_pt - i, i);
	}
}

ssize_t		read_lines(char **dest, int fileno)
{
	char		buf[BUFSIZ];
	char		*str;
	ssize_t		rb;
	ssize_t		ret;

	ret = 0;
	while ((rb = read(fileno, buf, BUFSIZ - 1)) == (BUFSIZ - 1)) {
		buf[BUFSIZ] = '\0';
		while ((str = get_next_line((const char *) buf)))
			*(dest + ret++) = str;

		get_next_line(NULL);
	}

	buf[rb] = '\0';
	while ((str = get_next_line((const char *) buf)))
		*(dest + ret++) = str;

	get_next_line(NULL);
	return (ret);
}

