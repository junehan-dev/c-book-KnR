#include <stdio.h>
#define MAXLINE 1000

int		max;
char	line[MAXLINE];
char	longest[MAXLINE];
int		get_line(void);
void	copy(void);

int	main(void)
{
	int			len;
	extern int	max;
	extern char	longest[];

	max = 0;
	while ((len = get_line()) > 0) {
		if (len > max) {
			max = len;
			copy();
		}
	}
	if (max > 0)
		printf("%s", longest);

	return (0);
}

int	get_line(void)
{
	int				c;
	int				i;
	extern char		line[];

	i = 0;
	c = getchar();
	while (i < MAXLINE - 1 && c != EOF && c != '\n') {
		line[i] = c;
		i++;
		c = getchar();
	}

	if (c == '\n')
		line[i++] = c;

	line[i] = '\0';
	return (i);
}

void	copy(void)
{
	int			i;
	extern char	line[];
	extern char	longest[];

	i = 0;
	longest[i] = line[i];
	while (longest[i++])
		longest[i] = line[i];
}

