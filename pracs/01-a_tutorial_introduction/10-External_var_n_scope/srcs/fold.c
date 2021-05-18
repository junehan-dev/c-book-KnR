#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "ft_extern.h"
#define NL	'\n'


int		main(int argc, const char *argv[])
{
	const char	*start;
	const char	*end;
	int			counts[1];

	if (argc < 2)
		return (0);

	assert(argc == 2);
	counts[0] = 0;
	start = argv[1];
	
	while ((end = next_paragraph(start))) {
		assert(*(end - 1) == NL);
		counts[0]++;
		fstring("paragraph %d: ", counts);
		write(STDOUT_FILENO, start, end - start);
		start = end;
	}
	assert(end == NULL); 
	counts[0]++;
	fstring("paragraph %d: ", counts);
	write(STDOUT_FILENO, start, strlen(start));
	return (0);
}

