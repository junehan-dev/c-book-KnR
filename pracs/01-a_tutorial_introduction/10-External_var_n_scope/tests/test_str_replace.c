#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_string.h"

void	test_str_replace(void)
{
	const char *input = "my  day\t is \t";
	char *replaced = ft_strreplace(input, "\t", " ");
	printf("'%s'", replaced);
	free(replaced);

	//assert(!strcmp(replaced, "my  day     is     "));

/*
	replaced = ft_strreplace(input, "  ","\t");
	assert(!strcmp(replaced, "my\tday\t is \t"));
	free(replaced);
*/
}

int main(void)
{
	test_str_replace();
	return (0);
}
