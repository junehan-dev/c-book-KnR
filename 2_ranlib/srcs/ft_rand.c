#define	FT_RANDMAX	2147483647

unsigned long int next = 0;

int		ft_rand(void)
{
	extern unsigned long int	next;

	if (!next)
		next = 1;

	next = next * 1103515245 + 12345;

	return (((unsigned int)(next / 65536)) % FT_RANDMAX);
}

void	ft_srand(unsigned int seed)
{
	extern unsigned long int	next;

	next = seed;
}

