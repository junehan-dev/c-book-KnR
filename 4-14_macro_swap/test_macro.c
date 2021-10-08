#include <assert.h>
#include "./ft_swap.h"

int	main(void)
{
	int i;
	int j;

	i = 4;
	j = 10;
	ft_swap_m(int, i, j);
	assert(i == 10);
	assert(j == 4);
	return (0);
}
