#include <stdio.h>

int	ft_strrindex(const char *s, int t);

int	main(int argc, const char *argv[])
{
	int found_index;

	if (argc == 3) {
		found_index = ft_strrindex(argv[1], *argv[2]);
		if (found_index != -1)
			printf("%c found at '%s'.\n", *argv[2], argv[1] + found_index);
		else
			printf("%c not found in '%s'.\n", *argv[2], argv[1]);

		return (0);
	}

	printf("program input, $1 : string, $2: chartofind not provided.\n");
	return (1);

}

