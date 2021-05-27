#include "ft_extern.h"

int		detab(char *src, int nth);

int 	main(void)
{
	extern char line[];
	int	i;
	
	while (get_line()) {
		i = 0;
		while (*(line + i))
			i = (*(line + i) == '\t') ? detab(line, i) : (i + 1);
		i = 0;
		printf("%s\n", line);
	}
}

int		detab(char *src, int nth)
{
	char	buf[MAXLINE];
	int		i;

	copy(buf, (const char *)(src + nth + 1));
	copy(src + nth, "    \0");
	copy(src + nth + 4, (const char *)buf);
	i = 4;
	while (i--)
		assert(*(src + nth + i) == ' ');
	assert(*(src + nth + 4) == buf[0]);
	return (nth + 4);
}

