#include "ft_extern.h"

int		entab(char *src, int nth);
int		is_entab(char *src);

int		main(void)
{
	int			i;
	char		ch;
	extern char	line[];

	while (get_line()) {
		i = 0;
		
		while ((ch = *(line + i))) {
			if (ch == ' ' && is_entab(line + i))
				entab(line, i);
			printf("%c: %d\n", *(line + i), *(line + i));
			i++;
		}
	}
}

int		is_entab(char *src)
{
	int	i;

	i = 3;
	while (i)
		if (*(src + i--) != ' ')
			return (0);
	return (1);
}

int		entab(char *src, int nth)
{
	char	buf[MAXLINE];

	copy(buf, (src + nth + 4));
	copy((src + nth), "\t\0");
	copy(src + nth + 1, buf);
	assert(*(src + nth) == '\t');
	assert(*(buf) == *(src + nth + 1));
	return (nth + 1);
}

