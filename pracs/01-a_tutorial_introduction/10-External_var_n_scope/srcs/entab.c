#include "ft_extern.h"

int		entab(char *src, int nth);
int		is_entab(char *src);

int		main(void)
{
	int			i;
	char		ch;
	int			occurences[2];
	extern char	line[];
	

	while (get_line()) {
		i = 0;
		occurences[0] = 0;
		occurences[1] = 0;
		while ((ch = *(line + i))) {
			if (ch == ' ') {
				if (is_entab(line + i)) {
					entab(line, i);
					occurences[1] += 1;
				} else
					occurences[0] += 1;
			}
			i++;
		}
		fstring("spaces: %d, new tabs: %d.\n", occurences);
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

