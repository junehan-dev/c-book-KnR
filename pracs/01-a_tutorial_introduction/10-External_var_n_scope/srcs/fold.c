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
	const char	**col_pt;
	int			arg;

	if (argc < 2)
		return (0);

	assert(argc > 1);

	arg = 1;
	while (arg < argc) {
		set_paragraph(pars, argv[arg++]);
		par_pt = pars;
		while (*(par_pt + 1)) {
			col_pt = cols;
			while (*(col_pt + 1)) {
				col_pt++;
			}
			par_pt++;
		}
		set_column(cols, *par_pt, strlen(*(par_pt)));
		col_pt = cols;
		while (*(col_pt + 1)) {
			col_pt++;
		}
		assert(*(par_pt + 1) == NULL);
		
	}
	return (0);
}

size_t	set_column(const char **cols, const char *src, size_t srclen)
{
	size_t		ret;
	ssize_t		offset;
	const char	*colend;
	const char	*colnext;

	ret = 0;
	*cols = src;
	while (srclen > 0 && (offset = next_column(*(cols + ret))) > 0) {
		srclen -= (size_t)offset;
		colend = *(cols + ret++) + offset;
		colnext	= colend + 1;
		assert(*colend == '.');
		assert(*colnext == ' '|| *colnext == '\t');
		*(cols + ret) = colnext;
	}
	*(cols + ret++) = NULL;
	int	lens[1] = {srclen};
	fstring("left :%d", lens);
	assert(srclen == 0);

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
		assert(*(start - 1) == NL);
		*dest++ = start;
		ret++;
	}
	assert(start == NULL); 
	*dest = start;
	return (ret);
}

