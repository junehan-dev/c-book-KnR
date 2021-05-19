#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "ft_extern.h"
#define NL	'\n'

size_t	set_paragraph(const char **dest, const char *src);

int		main(int argc, const char *argv[])
{
	const char	*paras[MAXLINE];
	const char	**para_pt;
	int			arg;

	if (argc < 2)
		return (0);
	assert(argc > 1);

	arg = 1;
	while (arg < argc) {
		set_paragraph(paras, argv[arg++]);
		para_pt = paras;
		while (*para_pt) {
			write(STDOUT_FILENO, *para_pt, *(para_pt + 1) - *para_pt - 1);
			para_pt++;
		}
	}
	return (0);
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

