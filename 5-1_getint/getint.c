#include <ctype.h>
#include <stdio.h>

/* getint: get next int from input into *pn */
int	getint(int *pn)
{
	int	c, sign;
	FILE *fd;

	fd = fdopen(0, "r");
	while (isspace(c = getc(fd)));
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetc(c, fd);
		return (0);
	}

	sign = (c == '-') ? -1 : 1;
	for (*pn = 0; isdigit(c); c = getc(fd))
		*pn = 10 * *pn + (c - '0');

	*pn *= sign;
	if (c != EOF)
		ungetc(c, fd);
	
	fclose(fd);
	return (c);
}

int	main(void)
{
	int arr[10];

	int i;
	int ret;

	i = 0;
	while (i < 10) {
		ret = getint(arr + i);
		if (ret > 0) {
			printf("%d\n", arr[i++]);
		} else {
			printf("non int\n");
			return (1);
		}
	}
	return (0);
}
