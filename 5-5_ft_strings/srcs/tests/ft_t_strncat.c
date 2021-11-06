#include <unistd.h>
#include <assert.h>
#include <stdio.h>

char	*ft_strncat(char *restrict dest, const char *restrict src, size_t n);

#include <string.h>
void	test_strncat(void)
{
	char	check[128] = "first data.";
	char	expect[128] = "first data.";
	
	printf("ft_strnat: '%s'\nstrncat: '%s'\n\n", check, expect);
	assert(
		*(strncat(expect, "\tnew data", 5)) == 
		*(ft_strncat(check, "\tnew data", 5))
	);
	assert(
		!strcmp(expect, check)
	);

	printf("ft_strnat: '%s'\nstrncat: '%s'\n\n", check, expect);
	assert(
		*(strncat(expect, "\ttwo data", 0)) == 
		*(ft_strncat(check, "\ttwo data", 0))
	);
	assert(
		!strcmp(expect, check)
	);

	printf("ft_strnat: '%s'\nstrncat: '%s'\n\n", check, expect);
	assert(
		*(strncat(expect, "\tthree data", 12)) == 
		*(ft_strncat(check, "\tthree data", 12))
	);
	assert(
		!strcmp(expect, check)
	);
	printf("ft_strnat: '%s'\nstrncat: '%s'\n\n", check, expect);
	assert(
		*(strncat(expect, "\tlast data", 20)) == 
		*(ft_strncat(check, "\tlast data", 20))
	);
	assert(
		!strcmp(expect, check)
	);
	printf("ft_strnat: '%s'\nstrncat: '%s'\n\n", check, expect);

}

int	main(void)
{
	test_strncat();
	return (0);
}
