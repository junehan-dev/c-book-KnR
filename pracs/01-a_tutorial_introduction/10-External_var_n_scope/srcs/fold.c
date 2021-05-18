#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include "ft_extern.h"
#define NL	'\n'


int		main(int argc, const char *argv[])
{
	const char	*pg;
	int			counts[1];

	assert(argc == 2);
	
	counts[0] = 0;
	pg = next_paragraph(argv[1]);
	
	while ((pg = next_paragraph(pg)) != NULL) {
		assert(isalnum((int)*pg));
		assert(*(pg - 1) == NL);
		counts[0]++;
		fstring("----pg: %d----\n", counts);
	}
	assert(pg == NULL); 
	return (0);
}

