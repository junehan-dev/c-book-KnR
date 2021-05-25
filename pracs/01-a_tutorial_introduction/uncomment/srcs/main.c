#include <assert.h>
#include <unistd.h>
#include <string.h>

char	*remove_comment(char *src);
int		main(int argc, const char *argv[])
{
	char 	origin[] = "this is /* comment */ string /* yet */.";
	size_t	len;
	size_t	last;
	size_t	i;

	len = strlen(origin);
	remove_comment(origin);
	last = 0;
	
	while (i < len) {
		while (!origin[i] && i < len)
			i++;
		origin[last++] = origin[i++];
	}
	write(STDOUT_FILENO, origin, strlen(origin));
}

ssize_t	comment_chr(char *src, )
{
	char		*src_pt;
	static char qute = 0;

	src_pt = src;
	while (*src_pt) {
		if (*src_pt == '/' && qute) {
			if (*(++src_pt) == '*')
				return (src_pt - src);
		} else if (*src_pt == '\\' && *(src_pt + 1 == '"')){
			src_pt += 2;
		} else if (*src_pt == '"') {
			qute = ~qute;
		} else
			src_pt++;
	}
	return (-1);
}

char	*remove_comment(char *src)
{
	size_t		i;
	char		ch;
	static char	qute = 0;

	i = 0;
	while ((ch = *(src + i))) {
		if (ch == '"') {
			qute = ~qute;
			i++;
		} else {
			if (!qute && ch == '/') {
				if (*(src + i + 1) == '*') {
					while (*(src + i) != '*' && *(src + i + 1) != '/' && *(src + i))
					 	*(src + i++) = 'a';
					if (*(src + i))
						*(src + i++) = 'a';
					*(src + i) = '\0';
				}
			} else {
				i++;
			}
		}
	}
	return (src);
}
