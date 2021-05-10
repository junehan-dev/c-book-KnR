#include <unistd.h>
#include <string.h>
#include <stdio.h>

void		*strmap(const char *src, ssize_t(*callback) (void *src))
{
	if (callback((void *)src))
		return ((void *)src);

	return (NULL);
}

