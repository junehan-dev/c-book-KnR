#include "ft_extern.h"

void	entab(char *src);
int		is_entab(char *src);

int		main(void)
{
	int			i;
	int			occurences[2];
	extern char	line[];

	while (get_line()) {
		i = 0;
		occurences[0] = 0;
		occurences[1] = 0;
		while (*(line + i)) {
			if (*(line + i) == ' ') {
				if (is_entab(line + i)) {
					entab(line + i);
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

void		entab(char *src)
{
	char	buf[MAXLINE];

	*buf = '\t';
	copy(buf + 1, (src + 4));
	copy(src, buf);
	assert(*src == '\t');
	assert(*(buf + 1) == *(src + 1));
}

