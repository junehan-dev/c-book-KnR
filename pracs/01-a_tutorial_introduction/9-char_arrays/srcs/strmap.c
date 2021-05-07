#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef	ssize_t	(*callback) (void *src);
void		*strmap(const char *src, callback cmp_func)
{
	if (cmp_func((void *)src))
		return ((void *)src);

	return (NULL);
}

