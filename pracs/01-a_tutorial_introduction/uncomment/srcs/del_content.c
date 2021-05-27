#include <stddef.h>

size_t	del_content(char *start, char *end)
{
	size_t	ret;

	ret = 0;
	while ((start + ret) < end)
		*(start + ret++) = '\0';
	return (ret);
}

