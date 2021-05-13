#include <assert.h>
#include <string.h>
#include "ft_string.h"

char *str_replace(const char *src, const char *from, const char *to)
{
	char	*strs[];
	char	**splited;
	int		i;

	
	i = 0;
	while(*(splited+i))
}

int	main(void)
{
	const char *src = "original\t  string\t is\t   this\t    string";
	char *ret;
	ret = str_replace(src, "    ", "\t");
	assert(!strchr(ret, "original\t  string\t is\t   this\t\tstring"));
	

}


