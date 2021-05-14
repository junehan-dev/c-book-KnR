#include <assert.h>
#include "ft_string.h"

void	test_strstr(void)
{
	const char *input = "myday\tis\t";
	char *occurence = ft_strstr(input, "\t");
	assert(occurence == (input + 5));
	occurence = ft_strstr(occurence + 1, "\t");
	assert(occurence == (input + 8));
}

int main(void)
{
	test_strstr();
	return (0);
}
