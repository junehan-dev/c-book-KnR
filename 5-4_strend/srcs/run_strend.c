#include <stdio.h>
#include <assert.h>
#include "ft_strend.h"

int	main(int argc, const char *argv[])
{
	assert(argc == 3);
	(argc == 3) ? ((ft_strend(argv[1] , argv[2])) ? printf("found") : printf("no found")) : printf("wrong input");
	
	return (0);
}
