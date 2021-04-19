#include <stdio.h>
#include <stdlib.h>
#include "temp_converter.h"

int	main(int argc, char *argv[])
{
	float	cels;
	int		i;

	if (argc < 2)
		return (EXIT_SUCCESS);

	i = 1;
	while (i < argc) {
		cels = (float)atof(argv[i++]);
		printf("Celsius input : %3.1f, fahrenheit to: %3.1f\n", cels, celtofahr(cels));
	}
	return (EXIT_SUCCESS);
}


