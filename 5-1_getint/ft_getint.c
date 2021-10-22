#include <ctype.h>
#include <unistd.h>
#include <stdio.h>

int	close_fd(int c, FILE *fd)
{
	ungetc(c, fd);
	fclose(fd);
	return (0);
}

int	ft_getint(int *pn)
{
	int		c, sign;
	FILE	*in_fd;

	in_fd = fdopen(0, "r");
	write(1, "(0.0)\n", 4);
	while (isspace((c = getc(in_fd))))
		write(1, &c, 1);
	write(1, "(0)\n", 4);

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		write(1, "(1)\n", 4);
		return (close_fd(c, in_fd));
	}

	sign = (c == '-') ? -1 : 1;
	write(1, "(2)\n", 4);
	if (!isdigit(c)) {
		c = getc(in_fd);
		if (!isdigit(c))
			return (close_fd(c, in_fd));
	}

	*pn = 0;
	while (isdigit(c)) {
		*pn = 10 * *pn + (c - '0');
		c = getc(in_fd);
	}

	*pn *= sign;
	if (c != EOF && isspace(c)) {
		close_fd(c, in_fd);
		write(1, "(3)\n", 4);
		return (1);
	}

	fclose(in_fd);
	write(1, "(4)\n", 4);
	return (0);
}

int read_one(int *pn, FILE *fd)
{
	*pn = getc(fd);
	while (isspace(*pn))
		*pn = getc(fd);
	if (*pn == EOF)
		return (0);
	return (*pn);
}

int	main(void)
{
	int arr[10];
	int i;
	int	ret;
	FILE	*fd;

	i = 0;
	ret = 1;

	while (i < 10 && ret) {
		ret = ft_getint(arr + i);
		printf("i: %d\t: %d", i, arr[i]);
		i++;
	}

	i = 0;
	ret = 1;
	fd = fdopen(0, "r");
	while (i < 10 && ret) {
		ret = read_one(arr + i, fd);
		write(1, arr + i, 1);
		printf("i: %d\t", i);
		i++;
	}
	fclose(fd);
	return (0);
}
