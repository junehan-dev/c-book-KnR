#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "ft_extern.h"
#define NL	'\n'

size_t	set_paragraph(const char **dest, const char *src);
size_t	set_column(const char **dest, const char *src, size_t srclen);

int		main(int argc, const char *argv[])
{
	const char	*pars[MAXLINE];
	const char	*cols[MAXLINE];
	const char	**par_pt;
	int			arg;

	if (argc < 2)
		return (0);

	assert(argc > 1);

	arg = 1;
	while (arg < argc) {
		set_paragraph(pars, argv[arg++]);
		par_pt = pars;
		while (*(par_pt + 1)) {
			set_column(cols, *par_pt, *(par_pt + 1) - *par_pt);
			par_pt++;
		}
		set_column(cols, *par_pt, strlen(*(par_pt)));

		assert(*(par_pt + 1) == NULL);
	}
	return (0);
}

size_t	set_column(const char **cols, const char *src, size_t srclen)
{
	*cols = src;
	write(STDOUT_FILENO, "CALL set_col:\n", 14);
	return write(STDOUT_FILENO, src, srclen);
}

size_t	set_paragraph(const char **dest, const char *src)
{
	size_t		ret;
	const char	*start;

	ret = 1;
	start = src;
	*dest++ = start;
	while ((start = next_paragraph(start))) {
		assert(*(start - 1) == NL);
		*dest++ = start;
		ret++;
	}
	assert(start == NULL); 
	*dest = start;
	return (ret);
}

