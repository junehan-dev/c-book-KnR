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

char	*remove_comment(char *src)
{
	size_t		i;
	char		ch;
	static char	qute = 0;

	i = 0;
	while (ch = *(src + i)) {
		if (ch == '"')
			qute = ~qute;
		else if (!qute) {
			if (ch == '/' && *(src + i + 1) == '*') {
				while (*(src + i) != '*' && *(src + i + 1) != '/' && *(src + i))
				 	*(src + i++) = '\0';
				if (*(src + i))
					*(src + i++) = '\0';
				*(src + i) = '\0';
			}
		}
		i++;
	}
	return (src);
}
