#include <stdio.h>
#include "temp_converter.h"

int	main(void)
{
	int		i;
	int		fahr;

	i	= 0;
	while (i < 31) {
		fahr = 300 - i * 10;
		printf("fahr: %3.1f\t cel: %6.3f\n", (float)(fahr), (float)fahrtocel((float)(fahr)));
		i++;
	};

	return (0);
}
