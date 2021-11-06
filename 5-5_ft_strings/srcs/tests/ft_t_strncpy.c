#include <unistd.h>
#include <assert.h>
#include <stdio.h>

char	*ft_strncpy(char *restrict dest, const char *restrict src, size_t n);

#include <string.h>
void	test_strncpy(void)
{
	char	check[128] = "first data.";
	char	expect[128] = "first data.";
	
	printf("ft_strncpy: '%s'\nstrncpy: '%s'\n\n", check, expect);
	assert(
		*(strncpy(expect, "\tnew data", 1)) == 
		*(ft_strncpy(check, "\tnew data", 1))
	);
	assert(
		!strcmp(expect, check)
	);

	printf("ft_strncpy: '%s'\nstrncpy: '%s'\n\n", check, expect);
	assert(
		*(strncpy(expect, "\ttwo data", 0)) == 
		*(ft_strncpy(check, "\ttwo data", 0))
	);
	assert(
		!strcmp(expect, check)
	);

	printf("ft_strncpy: '%s'\nstrncpy: '%s'\n\n", check, expect);
	assert(
		*(strncpy(expect, "\tthree data", 4)) == 
		*(ft_strncpy(check, "\tthree data", 4))
	);
	assert(
		!strcmp(expect, check)
	);
	printf("ft_strncpy: '%s'\nstrncpy: '%s'\n\n", check, expect);
	assert(
		*(strncpy(expect, "\tlast data", 2)) == 
		*(ft_strncpy(check, "\tlast data", 2))
	);
	assert(
		!strcmp(expect, check)
	);
	printf("ft_strncpy: '%s'\nstrncpy: '%s'\n\n", check, expect);

}

int	main(void)
{
	test_strncpy();
	return (0);
}
