#include <unistd.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "ft_additionals.h"
#define MAXLEN 1024

int		ft_isblank(char *src)
{
	char	*src_pt;
	int		ret;

	ret = 0;
	src_pt = src;
	while (*src_pt)
		if (isspace((int)*src_pt++))
			ret++;

	return (ret);
}


ssize_t	ft_read_keys(char *nkeys)
{
	ssize_t	rb;

	rb = read(STDIN_FILENO, nkeys, MAXLEN);
	return (rb);
}


int		main(void)
{
	ssize_t		rb;
	char		buf[MAXLEN];
	char		*ret;
	
	rb = ft_read_keys(buf);
	assert(rb <= MAXLEN);
	ret = ft_itoa(ft_isblank(buf));
	write(STDOUT_FILENO, ret, strlen(ret));
	free(ret);
	return (0);
}
