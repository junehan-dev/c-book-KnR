#include <stdio.h>
void	ft_strcat(char *dest, const char *src);

int	main(int argc, const char *argv[])
{
	int i;
	char dest[64] = "";
	
	if (argc <= 1)
		return (0);

	i = 1;
	while (i < argc) {
		ft_strcat(dest, argv[i]);
		printf("%dst argument added: '%s'\n", i, dest);
		i++;
	}

	return (0);
}

