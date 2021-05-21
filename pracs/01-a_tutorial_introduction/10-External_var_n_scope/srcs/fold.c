#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "ft_extern.h"
#define NL	'\n'

size_t	set_paragraph(const char **dest, const char *src);
size_t	set_column(const char **dest, const char *src);

int		main(int argc, const char *argv[])
{
	const char	*pars[MAXLINE];
	const char	*cols[MAXLINE];
	const char	**par_pt;
	const char	**col_pt;
	int			par_col_num[2] = {0};
	int			arg;

	if (argc < 2)
		return (0);

	assert(argc > 1);

	arg = 1;
	while (arg < argc) {
		set_paragraph(pars, argv[arg++]);
		par_pt = pars;
		while (*(par_pt + 1)) {
			par_col_num[0]++;
			set_column(cols, *par_pt);
			col_pt = cols;
			par_col_num[1] = 0;
			while (*(col_pt + 1)) {
				par_col_num[1]++;
				fstring("\nP:%d,C:%d -",  par_col_num);
				write(STDOUT_FILENO, *col_pt, *(col_pt + 1) - *col_pt);
				col_pt++;
			}
			assert(!*(col_pt + 1));
			par_col_num[1]++;
			fstring("\nP:%d,C:%d -",  par_col_num);
			write(STDOUT_FILENO, *col_pt, strlen(*col_pt));
			par_pt++;
		}

		assert(!*(par_pt + 1));	
		set_column(cols, *par_pt);
		col_pt = cols;
		par_col_num[1] = 0;
		while (*(col_pt + 1)) {
			par_col_num[1]++;
			fstring("\nP:%d,C:%d -",  par_col_num);
			write(STDOUT_FILENO, *col_pt, *(col_pt + 1) - *col_pt);
			col_pt++;
		}
		assert(!*(col_pt + 1));
		par_col_num[1]++;
		fstring("\nP:%d,C:%d -",  par_col_num);
		write(STDOUT_FILENO, col_pt, strlen(*col_pt));
	}
	return (0);
}

size_t	set_column(const char **cols, const char *src)
{
	size_t		ret;
	const char	*colnext;
	const char	*colend;

	ret = 0;
	*(cols + ret) = src;
	while ((colnext = next_column(*(cols + ret++)))) {
		colend = colnext - 1;
		assert(*colend == '.' || !*colend || *colend == '\n');
		*(cols + ret) = colnext;
	}
	*(cols + ret) = colnext;
	assert(*(cols + ret) == NULL);
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

