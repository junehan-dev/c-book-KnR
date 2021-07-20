#include <stdio.h>
#define MAXLINE	2048

int		get_line(void)
{
	int				c;
	int				i;
	extern char		line[];

	i = 0;
	c = getchar();
	while (i < MAXLINE - 1 && c != EOF && c != '\n') {
		line[i++] = c;
		c = getchar();
		if (c == EOF)
			return (0);
	}

	if (c == '\n')
		line[i++] = c;

	line[i] = '\0';
	return (i);
}
