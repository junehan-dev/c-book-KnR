#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "ft_extern.h"
#define NL	'\n'

size_t	set_paragraph(const char **dest, const char *src);
size_t	set_column(const char **dest, const char *src);
char	*fold(char *src);

int		main(int argc, const char *argv[])
{
	const char	*pars[MAXLINE];
	const char	*cols[MAXLINE];
	const char	**par_pt;
	const char	**col_pt;
	int			i;

	if (argc < 2)
		return (0);

	i = atoi(argv[2]);
	set_paragraph(pars, argv[1]);
	par_pt = pars;
	while (*(par_pt + 1) && i) {
		set_column(cols, *par_pt);
		col_pt = cols;
		while (*(col_pt + 1) && i) {
			i--;
			col_pt++;
		}
		par_pt++;
	}
	if (i) {
		set_column(cols, *par_pt);
		col_pt = cols;
		while (*(col_pt + 1) && i--)
			col_pt++;
	}

	write(STDOUT_FILENO, *col_pt, next_column(*col_pt) - *col_pt);
	fold((char *)((*col_pt) - 1));
	return (0);
}

char	*fold(char *src)
{
	*src = '\n';
	write(STDOUT_FILENO, src, next_column(src) - src);
	return (src);
}

size_t	set_column(const char **cols, const char *src)
{
	size_t		ret;
	const char	*colnext;

	ret = 0;
	*(cols + ret) = src;
	while ((colnext = next_column(*(cols + ret++))))
		*(cols + ret) = colnext;
	*(cols + ret) = colnext;
	return (ret);
}

size_t	set_paragraph(const char **dest, const char *src)
{
	size_t		ret;
	const char	*start;

	ret = 1;
	start = src;
	*dest++ = start;
	while ((start = next_paragraph(start))) {
		*dest++ = start;
		ret++;
	}
	*dest = start;
	return (ret);
}

