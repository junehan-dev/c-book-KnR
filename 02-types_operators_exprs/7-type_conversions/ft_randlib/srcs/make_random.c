#include <stdio.h>
#include "ft_randlib.h"

int	main(int argc, const char *argv[])
{
	int max;
	int	rand_v;
	int	seed;

	max = 0;
	if (argc > 1)
		max = ft_atoi(argv[1]);

	if (max < 0)
		return (1);

	seed = 0;
	if (argc == 3)
		seed = ft_atoi(argv[2]);
	printf("seed :%d\n", seed);
	
	if (seed)
		ft_srand(seed);

	rand_v = ft_rand();
	rand_v = (max) ? (rand_v % ++max) : rand_v;
	printf("%d", rand_v);

	return (rand_v);
}

